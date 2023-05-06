/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:00:46 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/06 19:36:59 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int open_file(t_data *data)
{
	t_file	*files;
	char *str;

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
		if (data->fd[0] == -1)
		{
			str = ft_strjoin("Minishell: ", files->name);
			ft_error(str);
			free(str);
			return (-1);
		}
		files = files->next;
	}
	return (1);
}

void	redirect(int x, int j)
{
	dup2(j, 1);
	dup2(x, 0);
}