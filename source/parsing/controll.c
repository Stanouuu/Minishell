/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:11:06 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/13 22:38:17 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	road(t_data *data)
{
	if (ft_command(data) == -1)
		return (-1);
	// while (data)
	// {
	// 	close(data->fd[0]);
	// 	data = data->next;
	// }
	return (1);
}
