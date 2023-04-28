/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:00:46 by sbarrage          #+#    #+#             */
/*   Updated: 2023/04/28 11:57:22 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	file_input(t_data *data, int i)
{
	if (dup2(*data->fd, 0) < 0)
		return (0);
	while (data->command[i])
	{
		data->command[i] = NULL;
		i++;
	}
	return (1);
}

int output_file(t_data *data, int i)
{
	if (dup2(*data->fd, 1) < 0)
		return (0);
	while (data->command[i])
	{
		data->command[i] = NULL;
		i++;
	}
	return (1);
}

int redirection(t_data *data)
{
	int	i;

	i = 0;
	while (data->command[i] && data->command[i + 1])
	{
		if (is_redirection(data->command[i]) == 1 || is_redirection(data->command[i]) == 2)
		{
			if (output_file(data, i) == 0)
				return (0);
		}
		else if (is_redirection(data->command[i]) == 3)
		{
			if (file_input(data, i) == 0)
				return (0);

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
	return (1);

}
