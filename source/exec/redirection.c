/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:00:46 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/07 22:53:32 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int open_file(t_data *data)
{
	t_file	*files;
	char *str;

	files = data->files;
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
		files = files->next;
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
		data->fd[1] = pip[1];
		data->next->fd[0] = pip[0];
		data = data->next;
	}
	data->fd[1] = j;
	return (1);
}
