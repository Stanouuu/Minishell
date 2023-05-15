/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:54:04 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/15 23:10:08 by stan             ###   ########.fr       */
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

int	until_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=' && str[i] != '+')
		i++;
	if (!str[i] && i != 0)
		return (i);
	return (i);
}
