/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:45:32 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/16 14:47:16 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_action(int num)
{
	if (num == SIGINT)
	{
		g_exitcode = 130;
		exit(g_exitcode);
	}
}

void	extra_cmd(t_data *data, char *str)
{
	signal(SIGINT, &child_action);
	signal(SIGQUIT, SIG_DFL);
	execve(str, data->command, data->envp);
	free(str);
	ft_dataclear(data);
}

int	forkland_2_the_forkening(t_data *data, int	*pid, int *j, char *str)
{
	int		i[2];

	i[1] = 0;
	i[0] = 1;
	while (data && i[0] > -1)
	{
		i[0] = straight_outta_forkton(i[0], data, j);
		if (i[0] == -1)
			return (-1);
		if (i[0] == 1)
		{
			i[0] = ft_check_error(data, &str);
			if (i[0] == -1)
				return (free(str), i[0]);
			if (i[0] != 0)
			{
				pid[i[1]] = fork();
				if (pid[i[1]] == 0 && i[0] == 1)
					forkgive_n_forkget(data, pid, j, &str);
				comewithmeifyouwanttofork(pid, i[1]++, data, &str);
			}
		}
		data = next_data(data, j[0], &(i[0]));
	}
	return (i[1]);
}
