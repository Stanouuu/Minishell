/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commandclose.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:16:14 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/16 16:19:11 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	firstcommandclose(t_data *data, int n, int x)
{
	if (data->fd[0] != -1 && data->fd[0] != x)
		close(data->fd[0]);
	if (data->next)
	{
		if (n == 1 && data->next->pipe[0] != -1)
			close(data->next->pipe[0]);
		if (data->next->pipe[1] != -1
			&& data->next->pipe[1] != data->fd[1])
			close(data->next->pipe[1]);
	}
	if (data->fd[1] != -1)
		close(data->fd[1]);
}

void	lastcommandclose(t_data *data, int n)
{
	(void)n;
	if (data->fd[1] != -1)
		close(data->fd[1]);
	if (data->pipe[1] != -1)
		close(data->pipe[1]);
	if (data->pipe[0] != data->fd[0]
		&& data->pipe[0] != -1)
		close(data->pipe[0]);
	if (data->fd[0] != -1)
		close(data->fd[0]);
}

void	middlecommandclose(t_data *data, int n)
{
	if (data->pipe[1] != -1)
		close(data->pipe[1]);
	if (n == 1 && data->next->pipe[0] != -1)
		close(data->next->pipe[0]);
	if (data->pipe[0] != data->fd[0]
		&& data->pipe[0] != -1)
		close(data->pipe[0]);
	if (data->next->pipe[1] != data->fd[1]
		&& data->next->pipe[1] != -1)
		close(data->next->pipe[1]);
	if (data->fd[0] != -1)
		close(data->fd[0]);
	if (data->fd[1] != -1)
		close(data->fd[1]);
}
