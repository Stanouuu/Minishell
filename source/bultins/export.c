/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:33:51 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/15 13:43:15 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cpytab_to_another(char **envp, char ***envpcpy)
{
	int		i;

	i = 0;
	while (envp[i])
		i++;
	*envpcpy = malloc(sizeof(char *) * (i + 1));
	if (!*envpcpy)
		return (ft_free_strs(envp), malloc_error());
	i = 0;
	while (envp[i])
	{
		(*envpcpy)[i] = ft_strdup(envp[i]);
		if (!(*envpcpy)[i])
		{
			while (i != 0)
				free((*envpcpy)[--i]);
			return (ft_free_strs(envp), malloc_error());
		}
		i++;
	}
	(*envpcpy)[i] = NULL;
	ft_free_strs(envp);
	return (1);
}

int	ft_add_env(char **cmd, char ***envp, int j, char **envpcpy)
{
	int		i;

	i = 0;
	while ((*envp)[i])
		i++;
	envpcpy = malloc(sizeof(char *) * (i + 2));
	if (!envpcpy)
		return (malloc_error());
	i = 0;
	while ((*envp)[i])
	{
		envpcpy[i] = ft_strdup((*envp)[i]);
		if (!envpcpy[i])
		{
			while (i != 0)
				free(envpcpy[--i]);
			free(envpcpy);
			return (malloc_error());
		}
		i++;
	}
	envpcpy[i] = ft_strdup(cmd[j]);
	if (!envpcpy[i])
	{
		while (i != 0)
			free(envpcpy[--i]);
		free(envpcpy);
		return (malloc_error());
	}
	envpcpy[i + 1] = NULL;
	ft_free_strs(*envp);
	return (cpytab_to_another(envpcpy, envp));
}

int	until_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (!str[i] && i != 0)
		return (i);
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

int	export(char **cmd, char ***envp)
{
	int	i;
	int	j;

	j = 1;
	if (!cmd[1])
	{
		if (envp_prt_sort(*envp) == -1)
			return (-1);
	}
	while (cmd[j])
	{
		i = 0;
		while (cmd[j][i] && !(cmd[j][i] == '=' && i != 0))
		{
			if ((cmd[j][i] == '=' && i != 0))
				ft_printf("the statement : = and i not 0 is true");
			if (ft_isalpha(cmd[j][i]) == 0)
			{
				write(2, "bash: export: ", 14);
				write(2, cmd[j], ft_strlen(cmd[j]));
				write(2, ": not a valid identifier\n", 25);
				break ;
			}
			else if (export_1(cmd, envp, j) == -1)
				return (-1);
			i++;
		}
		j++;
	}
	return (0);
}
