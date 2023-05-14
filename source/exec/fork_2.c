/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:55:12 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/14 16:24:47 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	comewithmeifyouwanttofork(int *pid, int y, t_data *data, char **str)
{
	if (pid[y] < 0)
		ft_error("fork");
	(void)data;
	if (*str)
		free(*str);
}

int	the_fork_outa_names(t_data *data, int x, int j)
{
	int	i;

	redirect(data->fd[0], data->fd[1]);
	i = ft_controller(data);
	redirect(x, j);
	return (i);
}

t_data	*next_data(t_data *data, int x)
{
	if (data->index == 0)
		firstcommandclose(data, 0, x);
	else if (data->next == NULL && data->index != 0)
		lastcommandclose(data, 0);
	else
		middlecommandclose(data, 0);
	return (data->next);
}

void	forkgive_n_forkget(t_data *data, int *pid, int *j, char **str)
{
	ft_printf("J : %d - %d\n", j[0], j[1]);
	ft_printf("I : %d - %d\n", data->fd[0], data->fd[1]);
	ft_printf("pipe : %d - %d\n", data->pipe[0], data->pipe[1]);
	forkland(data, pid, j);
	extra_cmd(data, *str);
	exit(127);
}

int	the_forkiest_fork(t_data *data, int i)
{
	if (data->next && i == 0)
		i = 1;
	return (i);
}
