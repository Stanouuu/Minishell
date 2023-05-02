/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:00:46 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/02 19:02:35 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int open_file(t_data *data)
{
	t_file	*files;

	files = data->files;
	data->fd[0] = dup(0);
	data->fd[1] = dup(1);
	while (files)
	{
		if (files->type == 4)
		{
			fclose(fopen(files->name, "w"));
			data->fd[1] = open(files->name, O_WRONLY);
		}
		if (files->type == 3)
			data->fd[1] = open(files->name, O_WRONLY | O_APPEND);
		if (files->type == 1)
			data->fd[0] = open(files->name, O_RDONLY);
		files = files->next;
	}
	return (1);
}

void	redirect(int x, int j)
{
	dup2(j, 1);
	dup2(x, 0);
}