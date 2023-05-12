/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:45:32 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/12 21:06:36 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_action(int num, siginfo_t	*info, void *content)
{
	if (num == SIGINT && content)
		kill(info->si_pid, SIGTERM);
}

void	extra_cmd(t_data *data, char *str)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGINT);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = &child_action;
	sigaction(SIGUSR1, &sa, NULL);
	// signal(SIGQUIT, SIGQUIT);
	execve(str, data->command, data->envp);
	free(str);
	ft_dataclear(data);
	g_exitcode = 127;
}

int	forkland_2_the_forkening(t_data *data, int	*pid, int *j, char *str)
{
	int		i;
	int		y;

	y = 0;
	i = open_file(data);
	while (data && i > -1)
	{
		i = straight_outta_forkton(i, data, j);
		if (i == -1)
			return (-1);
		if (i == 1)
		{
			i = ft_check_error(data, &str);
			if (i == -1)
				return (free(str), i);
			if (i != 0)
			{
				printf("%s", str);
				pid[y] = fork();
				if (pid[y] == 0 && i == 1)
					forkgive_n_forkget(data, pid, j, &str);
				comewithmeifyouwanttofork(pid, y++, data, &str);
			}
		}
		i = the_forkiest_fork(data, i);
		data = next_data(data);
	}
	return (y);
}
