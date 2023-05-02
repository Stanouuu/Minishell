/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:37:56 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/02 22:42:49 by sbarrage         ###   ########.fr       */
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

void	extra_cmd(t_data *data)
{
	char				*str;
	struct sigaction	sa;

	// char *cat = "cat";
	// int i = -1;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGINT);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = &child_action;
	sigaction(SIGUSR1, &sa, NULL);
	if (data->command[0][0] == '.' && data->command[0][1] == '/')
	{
		execv(data->command[0], data->command + 1);
		str = ft_strjoin("Minishell: ", data->command[0]);
		ft_error(str);
		free(str);
		return ;
	}
	else
	{
		str = ft_strjoin("/usr/bin/", data->command[0]);
		if (!str)
			ft_error("malloc");
		execve(str, data->command, data->envp);
		free(str);
	}
	str = ft_strjoin(data->command[0], ": command not found\n");
	write(2, str, ft_strlen(str));
	free(str);
}

int ft_controller(t_data *data)
{
	if (data->command && ft_strcmp("exit", data->command[0]) == 0)
		return (-1);
	else if (data->command && ft_strcmp("echo", data->command[0]) == 0)
		echo(data->command);
	else if (data->command && ft_strcmp("pwd", data->command[0]) == 0)
		pwd(data->command);
	else if (data->command && ft_strcmp("cd", data->command[0]) == 0)
		cd(data->command);
	else if (data->command && ft_strcmp("env", data->command[0]) == 0)
		env(data->command, data->envp);
	else if (data->command && ft_strcmp("unset", data->command[0]) == 0)
		unset(data->command, data->envp);
	else if (data->command && ft_strcmp("export", data->command[0]) == 0)
		export(data->command, data->envp);
	else
		return (0);
	return (1);
}

int	ft_command(t_data *data)
{
	pid_t	pid;
	int		j;
	int 	x;
	int 	i;

	j = dup(1);
	x = dup(0);
	i = 0;
	if (open_file(data) == 1)
	{
		redirect(data->fd[0], data->fd[1]);
		i = ft_controller(data);
	}
	if (i == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			extra_cmd(data);
			redirect(x, j);
			exit(0);
		}
		else if (pid < 0)
			ft_error("fork");
		else
			ft_parent();
	}
	redirect(x, j);
	if (i == -1)
		return (-1);
	return (1);
}
