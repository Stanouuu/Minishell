/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:00:46 by sbarrage          #+#    #+#             */
/*   Updated: 2023/02/21 16:09:22 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	controller(t_data **data)
{
	int	i;

	i = 0;
	while ((*data)->command[i])
	{
		if (ft_strncmp(">", (*data)->command[i], 2) == 0 || ft_strncmp(">>", (*data)->command[i], 3) == 0)
		{
			dup2(*(*data)->fd, 1);
				// dup2(*(*data)->fd, 1);
			while ((*data)->command[i])
			{
				// ft_printf("%s\n", (*data)->command[i]);
				(*data)->command[i] = NULL;
				i++;
			}
			return ;
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