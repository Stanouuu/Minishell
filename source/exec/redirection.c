/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:00:46 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/13 23:02:39 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_them_all(t_data *data, t_file *files)
{
	if (files->type == 4)
		data->fd[1] = open(files->name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (files->type == 3)
		data->fd[1] = open(files->name, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (files->type == 1)
		data->fd[0] = open(files->name, O_RDONLY);
	if (data->fd[0] == -1)
		return (0);
	return (1);
}

void	close_pip(t_data *data, t_file *files)
{
	if (data->next && data->next->pipe[1] != -1
		&& (files->type == 4 || files->type == 3))
		close (data->next->pipe[1]);
	else if (data->pipe[0] != -1
		&& (files->type == 1 || files->type == 2))
		close (data->pipe[0]);
}

int	open_file(t_data *data)
{
	t_file	*files;

	while (data)
	{
		files = data->files;
		while (files)
		{
			if (open_them_all(data, files) == 0)
				return (0);
			close_pip(data, files);
			files = files->next;
		}
		if (data->fd[0] == -1)
			g_exitcode = 1;
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
		printf("\n\n0[%d]1[%d]\n\n", pip[0], pip[1]);
		data->next->pipe[0] = pip[0];
		data->next->pipe[1] = pip[1];
		data->fd[1] = pip[1];
		data->next->fd[0] = pip[0];
		data = data->next;
	}
	data->fd[1] = j;
	return (1);
}
