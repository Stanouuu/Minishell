/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:58:36 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/13 21:32:27 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	the_fork_before_forks(int *pid, t_data *data, int x, int j)
{
	free(pid);
	redirect(data->fd[0], data->fd[1]);
	close (x);
	close (j);
}

void	forkland(t_data *data, int *pid, int *j)
{
	free(pid);
	redirect(data->fd[0], data->fd[1]);
	close (j[0]);
	close (j[1]);
	// close (data->next->fd[0]);
	while (data)
	{
		if (data->pipe[0] != -1)
		{
			close (data->fd[0]);
			close (data->fd[1]);
			close (data->pipe[1]);
			if (data->next)
				close (data->pipe[0]);
		}
		data = data->next;
	}
}

void	guns_n_forks(int x, int j, int *pid)
{
	free(pid);
	redirect(x, j);
	close (x);
	close (j);
}

int	straight_outta_forkton(int i, t_data *data, int *j)
{
	if (i >= 1)
		i = the_fork_outa_names(data, j[0], j[1]);
	return (i);
}
