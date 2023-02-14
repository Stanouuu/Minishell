/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:54:17 by sbarrage          #+#    #+#             */
/*   Updated: 2023/02/10 15:33:31 by sbarrage         ###   ########.fr       */
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
			if (ft_strncmp(cmd[j], envp[i], ft_strlen(cmd[j]) + 1) == -61)
			{
				ft_printf("%s", envp[i]);
				while (envp[i + 1])
				{
					envp[i] = envp[i + 1];
					i++;
				}
				envp[i] = NULL;
			}
			i++;
		}
		j++;
	}
}
