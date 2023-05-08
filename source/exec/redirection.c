/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:00:46 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/08 16:51:42 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int open_file(t_data *data)
{
	t_file	*files;
	char *str;

	while (data)
	{
		files = data->files;
		while (files)
		{
			if (files->type == 4)
				data->fd[1] = open(files->name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
			if (files->type == 3)
				data->fd[1] = open(files->name, O_CREAT | O_WRONLY | O_APPEND, 0644);
			if (files->type == 1)
				data->fd[0] = open(files->name, O_RDONLY);
			if (data->fd[0] == -1)
			{
				str = ft_strjoin("Minishell: ", files->name);
				if (!str)
				{
					ft_error("malloc");
					g_exitcode = 1;
					return (-1);
				}
				ft_error(str);
				free(str);
				return (0);
			}
			if (files->type == 4 || files->type == 3)
				close (data->pipe[1]);
			else if (files->type == 1|| files->type == 2)
				close (data->pipe[0]);
			files = files->next;
		}
		data = data->next;
	}
	return (1);
}

void	redirect(int x, int j)
{
	dup2(j, 1);
	dup2(x, 0);
}

int	ft_pipe(t_data *data, int j, int x)
{
	int	pip[2];

	data->fd[0] = x;
	while (data->next)
	{
		if (pipe(pip) > 0)
		{
			ft_error("Minishell: can't create pipe: ");
			g_exitcode = 141;
			return (-1);
		}
		data->pipe[0] = pip[0];
		data->pipe[1] = pip[1];
		data->fd[1] = pip[1];
		data->next->fd[0] = pip[0];
		data = data->next;
	}
	data->fd[1] = j;
	return (1);
}
