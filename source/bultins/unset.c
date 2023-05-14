/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:54:17 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/14 13:30:56 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset(char **cmd, char **envp)
{
	int	i;
	int	j;

	j = 1;
	while (cmd[j])
	{
		i = 0;
		while (envp[i])
		{
			if ((int)ft_strlen(cmd[j]) != until_equal(envp[i]))
			{
			}
			else if (ft_strncmp(cmd[j], envp[i], until_equal(envp[i])) == 0)
			{
				ft_printf("%s\n", envp[i]);
				while (envp[i + 1])
				{
					free(envp[i]);
					envp[i] = ft_strdup(envp[i + 1]);
					i++;
				}
				free(envp[i]);
				envp[i] = NULL;
			}
			i++;
		}
		j++;
	}
}
