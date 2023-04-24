/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:00:46 by sbarrage          #+#    #+#             */
/*   Updated: 2023/04/24 20:12:54 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void redirection(t_data *data)
{
	int	i;

	i = 0;
	while (data->command[i])
	{
		if (is_redirection(data->command[i]) == 1 || is_redirection(data->command[i]) == 2)
		{
			if (dup2(*data->fd, 1) < 0)
				return;
			while (data->command[i])
			{
				data->command[i] = NULL;
				i++;
			}
			return ;
		}
		if (ft_strncmp("<", data->command[i], 2) == 3)
		{
			if (dup2(*data->fd, 0) < 0)
				return ;
			while (data->command[i])
			{
				data->command[i] = NULL;
				i++;
			}
			return;
		}
		i++;
	}
	// dup2(*(*data)->fd, 1);
	// while ((*data)->command[i])
	// {
	// 	(*data)->command[i] = NULL;
	// 	i++;
	// 	ft_printf("%d\n", i);
	// }

}
