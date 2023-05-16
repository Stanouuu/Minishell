/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:33:51 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/16 12:05:27 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	export_2(char **cmd, char **envp, int j)
{
	int	k;
	int	i;

	k = 0;
	while (envp[k])
	{
		i = until_equal(envp[k]);
		if (ft_strncmp(cmd[j], envp[k], i) == 0
			&& until_equal(envp[k]) == until_equal(cmd[j]))
		{
			free(envp[k]);
			envp[k] = ft_strdup(cmd[j]);
			if (!envp[k])
				return (malloc_error());
			break ;
		}
		k++;
	}
	return (k);
}

int	export_1(char **cmd, char ***envp, int j)
{
	int	i;
	int	h;

	i = 0;
	if (cmd[j][i] == '=')
		return (1);
	h = export_2(cmd, *envp, j);
	if (h == -1)
		return (h);
	else if (!(*envp)[h])
	{
		if (ft_add_env(cmd, envp, j, NULL) == -1)
			return (-1);
	}
	else
		return (0);
	j++;
	return (0);
}

int	export_11(char **cmd, char ***envp, int i, int j)
{
	int	h;

	h = conca_export(cmd, envp, j);
	while (cmd[j][i] && !(cmd[j][i] == '=' && i != 0))
	{
		ft_printf("%d", h);
		if (h == -1)
			return (-1);
		else if (h == 1)
			break ;
		else if ((cmd[j][i] == '=' && i != 0))
			ft_printf("the statement : = and i not 0 is true");
		else if ((ft_isalpha(cmd[j][i]) == 0 && !(cmd[j][i] == '='))
			|| (ft_isalpha(cmd[j][i]) == 0))
		{
			ft_printf("bash: export: %s: not a valid identifier\n", cmd[j]);
			break ;
		}
		else if (export_1(cmd, envp, j) == -1)
			return (-1);
		i++;
	}
	return (h);
}

int	export(char **cmd, char ***envp)
{
	int	i;
	int	j;

	j = 0;
	if (!cmd[1] && envp_prt_sort(*envp) == -1)
		return (-1);
	while (cmd[++j])
	{
		i = 0;
		if (export_11(cmd, envp, i, j) == -1)
			return (-1);
	}
	return (0);
}
