/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:54:17 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/16 15:59:18 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_error(char ***envp, int i)
{
	int	j;

	j = i;
	i++;
	while ((*envp)[i])
		free((*envp)[i++]);
	while (j != 0)
		free((*envp)[--j]);
	free(*envp);
	*envp = NULL;
}

int	unset_2(char **cmd, int j, char ***envp, int i)
{
	if ((int)ft_strlen(cmd[j]) != until_equal((*envp)[i]))
	{
	}
	else if (ft_strncmp(cmd[j], (*envp)[i], until_equal((*envp)[i])) == 0)
	{
		while ((*envp)[i + 1])
		{
			free((*envp)[i]);
			(*envp)[i] = ft_strdup((*envp)[i + 1]);
			if (!(*envp)[i])
				return (unset_error(envp, i), malloc_error());
			i++;
		}
		free((*envp)[i]);
		(*envp)[i] = NULL;
	}
	return (i);
}

int	unset(char **cmd, char ***envp)
{
	int	i;
	int	j;

	j = 1;
	while (cmd[j])
	{
		i = 0;
		while ((*envp)[i])
		{
			i = unset_2(cmd, j, &(*envp), i);
			if (i != -1)
				i++;
			else
				return (-1);
		}
		j++;
	}
	return (0);
}
