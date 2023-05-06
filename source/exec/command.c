/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:37:56 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/06 20:46:36 by sbarrage         ###   ########.fr       */
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
	while (wait(NULL) > 0)
	{
	}
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
		execv(data->command[0], data->command + 1);
		return ;
	}
	else
	{
		execve(str, data->command, data->envp);
		free(str);
	}
	str = ft_strjoin(data->command[0], ": command not found\n");
	write(2, str, ft_strlen(str));
	free(str);
	ft_dataclear(data);
	g_exitcode = 127;
}

int	ft_exit(char **cmd)
{
	int	i;

	i = 0;
	if (cmd[1] && cmd[2])
		return (1);
	while (cmd[1] && cmd[1][i])
	{
		if (is_digit(cmd[1][i]) == 0)
		{
			g_exitcode = 2;
			return (-1);
		}
		i++;
	}
	// ft_printf("%s", cmd[1]);
	if (cmd[1])
		g_exitcode = ft_atoi(cmd[1]);
	// write(1, "ll", 2);
	return (-1);
}

int ft_controller(t_data *data)
{
	if (data->command && ft_strcmp("exit", data->command[0]) == 0)
		return (ft_exit(data->command));
	else if (data->command && ft_strcmp("echo", data->command[0]) == 0)
		echo(data->command);
	else if (data->command && ft_strcmp("pwd", data->command[0]) == 0)
		pwd(data->command);
	else if (data->command && ft_strcmp("cd", data->command[0]) == 0)
		cd(data->command, data->envp);
	else if (data->command && ft_strcmp("env", data->command[0]) == 0)
		env(data->command, data->envp);
	else if (data->command && ft_strcmp("unset", data->command[0]) == 0)
		unset(data->command, data->envp);
	else if (data->command && ft_strcmp("export", data->command[0]) == 0)
		export(data->command, data->envp);
	else
		return (1);
	return (0);
}

int	ft_command(t_data *data)
{
	pid_t	pid;
	char	*str;
	int		j;
	int 	x;
	int 	i;

	j = dup(1);
	x = dup(0);
	i = open_file(data);
	str = NULL;
	if (i == 1)
	{
		redirect(data->fd[0], data->fd[1]);
		i = ft_controller(data);
	}
	if (i == -1)
		return (-1);
	else if (i == 1)
	{
		ft_check_error(data, &str);
		if (!str)
			return (0);
		pid = fork();
		if (pid == 0)
		{
			extra_cmd(data, str);
			redirect(x, j);
			exit(0);
		}
		else if (pid < 0)
			ft_error("fork");
		else
			ft_parent();
	}
	redirect(x, j);
	return (1);
}
