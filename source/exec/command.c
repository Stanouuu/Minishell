/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:37:56 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/01 17:10:21 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	char	*str;

	if (data->command[0][0] == '.' && data->command[0][1] == '/')
	{
		execv(data->command[0], data->command + 1);
		str = ft_strjoin("Minishell: ", data->command[0]);
		ft_error(str);
		free(str);
	}
	else
	{
		str = ft_strjoin("/usr/bin/", data->command[0]);
		if (!str)
			ft_error("malloc");
		execv(str, data->command);
		free(str);
	}
	str = ft_strjoin(data->command[0], ": command not found\n");
	write(2, str, ft_strlen(str));
	free(str);
}

int open_file(t_data *data)
{
	t_file	*files;

	files = data->files;
	data->fd[0] = dup(0);
	data->fd[1] = dup(1);
	while (files)
	{
		if (files->type->enu == 3)
			data->fd[1] = open(files->name, O_WRONLY | O_APPEND);
		else if (files->type->enu == 4)
		{
			fclose(fopen(files->name, "w"));
			data->fd[1] = open(files->name, O_WRONLY);
		}
		else if (files->type->enu == 3)
			data->fd[0] = open(files->name, O_RDONLY);
	}
	return (1);
}

int ft_controller(t_data *data)
{
	if (data->command && ft_strcmp("exit", data->command[0]) == 0)
		return (0);
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
		extra_cmd(data);
	return (1);
}

int	ft_command(t_data *data)
{
	pid_t	pid;
	int	j;
	int x;
	int i;

	j = dup(1);
	x = dup(0);
	pid = fork();
	if (pid == 0)
	{
		if (open_file(data) == 1)
		{
			dup2(data->fd[1], 1);
			dup2(data->fd[0], 0);
			if (ft_controller(data) == 0)
				i = -1;
			dup2(j, 1);
			dup2(x, 0);
		}
		exit(0);
	}
	else if (pid < 0)
		ft_error("fork");
	else
		ft_parent();
	if (i == -1)
		return (-1);
	return (1);
}
