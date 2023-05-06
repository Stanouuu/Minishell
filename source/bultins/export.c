/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:33:51 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/05 19:18:33 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_env(char **cmd, char **envp, int j)
{
	int	i;

	i = 0;
	while (envp[i + 1])
		i++;
	envp[i + 1] = envp[i];
	if (cmd[1])
	{
		envp[i] = ft_strdup(cmd[j]);
		if (!envp[i])
			ft_error("malloc");
	}
	envp[i + 2] = NULL;
}

int	until_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

int	export_2(char **cmd, char **envp, int j)
{
	int	k;
	int	i;

	k = 0;
	i = until_equal(cmd[j]);
	while (envp[k])
	{
		if (ft_strncmp(cmd[j], envp[k], i) == 0)
		{
			envp[k] = ft_strdup(cmd[j]);
			if (!envp[k])
				ft_error("malloc");
			break ;
		}
		k++;
	}
	return (k);
}

void	export(char **cmd, char **envp)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	if (!cmd[1])
		envp_prt_sort(envp);
	while (cmd[j] && cmd[j][i] && !(cmd[j][i] == '=' && i != 0))
	{
		if ((cmd[j][i] == '=' && i != 0))
			ft_printf("the statement : = and i not 0 is true");
		if (ft_isalpha(cmd[j][i]) == 0)
		{
			write(2, "bash: export: ", 14);
			write(2, cmd[j], ft_strlen(cmd[j]));
			write(2, ": not a valid identifier\n", 25);
		}
		i++;
	}
	while (cmd[j])
	{
		i = 0;
		if (cmd[j][i] == '=')
			return ;
		while (cmd[j][i])
		{
			i++;
			if (cmd[j][i])
			{	
				if (!envp[export_2(cmd, envp, j)])
					ft_add_env(cmd, envp, j);
				break ;
			}
		}
		j++;
	}
}
