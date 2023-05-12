/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:33:51 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/12 20:35:47 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_add_env(char **cmd, char **envp, int j)
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
		{
			g_exitcode = 1;
			ft_error("malloc");
			return (-1);
		}
	}
	envp[i + 2] = NULL;
	return (1);
}

int	until_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (!str[i] && i != 0)
		return (i - 1);
	return (i);
}

int	export_2(char **cmd, char **envp, int j)
{
	int	k;
	int	i;

	k = 0;
	while (envp[k])
	{
		i = until_equal(cmd[j]);
		if (ft_strncmp(cmd[j], envp[k], i) == 0)
		{
			envp[k] = ft_strdup(cmd[j]);
			break ;
		}
		k++;
	}
	return (k);
}

int	export_1(char **cmd, char **envp, int j)
{
	int	i;
	int	h;

	while (cmd[j])
	{
		i = 0;
		if (cmd[j][i] == '=')
			return (1);
		h = export_2(cmd, envp, j);
		if (h == -1)
			return (h);
		else if (!envp[h])
		{
			if (ft_add_env(cmd, envp, j) == -1)
				return (-1);
		}
		else
			return (0);
		j++;
	}
	return (0);
}

int	export(char **cmd, char **envp)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	if (!cmd[1])
	{
		if (envp_prt_sort(envp) == -1)
			return (-1);
	}
	while (cmd[j] && cmd[j][i] && !(cmd[j][i] == '=' && i != 0))
	{
		if ((cmd[j][i] == '=' && i != 0))
			ft_printf("the statement : = and i not 0 is true");
		if (ft_isalpha(cmd[j][i]) == 0)
		{
			write(2, "bash: export: ", 14);
			write(2, cmd[j], ft_strlen(cmd[j]));
			write(2, ": not a valid identifier\n", 25);
			return (0);
		}
		i++;
	}
	return (export_1(cmd, envp, j));
}
