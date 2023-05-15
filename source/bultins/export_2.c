/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:24:15 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/15 17:29:04 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_add_env_2(char ***envp, char **envpcpy)
{
	int	i;

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
	return (i);
}

int	ft_add_env(char **cmd, char ***envp, int j, char **envpcpy)
{
	int	i;

	i = 0;
	while ((*envp)[i])
		i++;
	envpcpy = malloc(sizeof(char *) * (i + 2));
	if (!envpcpy)
		return (malloc_error());
	i = ft_add_env_2(envp, envpcpy);
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
