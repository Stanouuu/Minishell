/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:37:56 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/15 18:57:21 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_controller(t_data *data)
{
	if (data->command && ft_strcmp("exit", data->command[0]) == 0)
		return (close(data->fd[0]), close(data->fd[1]), ft_exit(data->command));
	else if (data->command && ft_strcmp("echo", data->command[0]) == 0)
		echo(data->command);
	else if (data->command && ft_strcmp("pwd", data->command[0]) == 0)
		pwd(data->command);
	else if (data->command && ft_strcmp("cd", data->command[0]) == 0)
		return (cd(data->command, data->envp));
	else if (data->command && ft_strcmp("env", data->command[0]) == 0)
		env(data->command, data->envp);
	else if (data->command && ft_strcmp("unset", data->command[0]) == 0)
		return (unset(data->command, &(data->envp)));
	else if (data->command && ft_strcmp("export", data->command[0]) == 0)
		return (export(data->command, &(data->envp)));
	else
		return (1);
	if (data->next)
		return (2);
	return (0);
}

int	all_data(t_data *data)
{
	int	i;

	i = 1;
	while (data)
	{
		data = data->next;
		i++;
	}
	return (i);
}

void	ft_parent(int *pid, int y)
{
	int	i;
	int	status;

	i = 0;
	signal(SIGINT, SIG_IGN);
	while (i != y)
	{
		if (waitpid(-1, &status, WUNTRACED) == pid[y - 1])
			g_exitcode = status / 256;
		i++;
	}
}

int	ft_command(t_data *data)
{
	pid_t	*pid;
	int		j[2];
	int		y;

	if (!data->command[0])
		return (0);
	y = 0;
	pid = malloc(sizeof(int) * all_data(data));
	if (!pid)
		return (malloc_error());
	pid[0] = -1;
	j[1] = dup(1);
	j[0] = dup(0);
	if (ft_pipe(data, j[1], j[0]) == -1)
		return (close (j[1]), close(j[0]), -1);
	y = forkland_2_the_forkening(data, pid, j, NULL);
	if (y == -1)
		return (close(j[1]), close(j[0]), free(pid), -1);
	if (pid[0] != -1)
		ft_parent(pid, y);
	return (guns_n_forks(j[0], j[1], pid), 1);
}
