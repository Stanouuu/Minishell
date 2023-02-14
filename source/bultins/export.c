/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:33:51 by sbarrage          #+#    #+#             */
/*   Updated: 2023/02/13 20:03:46 by sbarrage         ###   ########.fr       */
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
		envp[i] = ft_strdup(cmd[j]);
	envp[i + 2] = NULL;
}

int	export_2(char **cmd, char **envp, int i, int j)
{
	int	k;

	k = 0;
	while (envp[k])
	{
		if (ft_strncmp(cmd[j], envp[k], i) == 0)
		{
			envp[k] = ft_strdup(cmd[j]);
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
	if (!cmd[1])
		envp_prt_sort(envp);
	while (cmd[j])
	{
		i = 0;
		if (cmd[j][i] == '=')
			return ;
		while (cmd[j][i])
		{
			i++;
			if (cmd[j][i] == '=')
			{	
				if (!envp[export_2(cmd, envp, i, j)])
					ft_add_env(cmd, envp, j);
				break ;
			}
		}
		j++;
	}
}
