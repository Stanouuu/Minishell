/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:37:56 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/08 19:36:11 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_action(int num, siginfo_t	*info, void *content)
{
	if (num == SIGINT && content)
		kill(info->si_pid, SIGTERM);
}


int ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_parent(void)
{
	signal(SIGINT, SIG_IGN);
	waitpid(-1, 0, 0);
}

void	extra_cmd(t_data *data, char *str)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGINT);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = &child_action;
	sigaction(SIGUSR1, &sa, NULL);
	if (!str)
	{
		execve(data->command[0], data->command + 1, data->envp);
		return ;
	}
	else
	{
		execve(str, data->command, data->envp);
		free(str);
	}
	free(str);
	ft_dataclear(data);
	g_exitcode = 127;
}

int	ft_exit(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[1] && cmd[1][i])
	{
		if (is_digit(cmd[1][i]) == 0)
		{
			g_exitcode = 2;
			ft_printf("Minishell: %s: numeric argument required\n", cmd[1]);
			return (-1);
		}
		i++;
	}
	if (cmd[1] && cmd[2])
	{

		g_exitcode = 1;
		ft_printf("bash: exit: too many arguments\n");
		return (0);
	}
	if (cmd[1])
		g_exitcode = ft_atoi(cmd[1]);
	return (-1);
}

int ft_controller(t_data *data)
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
		unset(data->command, data->envp);
	else if (data->command && ft_strcmp("export", data->command[0]) == 0)
		return (export(data->command, data->envp));
	else
		return (1);
	if (data->next)
		return (2);
	return (0);
}

int	ft_command(t_data *data)
{
	pid_t	pid;
	char	*str;
	int		j;
	int 	x;
	int 	i;

	if (!data->command[0])
		return (0);
	j = dup(1);
	x = dup(0);
	if (ft_pipe(data, j, x) == -1)
		return (-1);
	i = open_file(data);
	str = NULL;
	while (data && i > -1)
	{
		if (i == 1)
		{
			redirect(data->fd[0], data->fd[1]);
			i = ft_controller(data);
			redirect(x, j);
		}
		if (i >= 1)
		{
			if (i == 2)
			{		
				close (data->fd[1]);
				data = data->next;
			}
			i = ft_check_error(data, &str);
			if (i == -1)
				return (free(str), i);
			if (i != 0)
			{
				pid = fork();
				if (pid == 0 && i == 1)
				{
					redirect(data->fd[0], data->fd[1]);
					extra_cmd(data, str);
					redirect(x, j);
					exit(0);
				}
				else if (pid < 0)
					ft_error("fork");
				else
					ft_parent();
				if (data->next)
					close (data->fd[1]);
				free(str);
			}
		}
		if (data->next && i == 0)
		{
			i = 1;
		}
		data = data->next;
	}
	return (i);
}
