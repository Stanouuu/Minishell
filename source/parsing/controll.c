/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:11:06 by sbarrage          #+#    #+#             */
/*   Updated: 2023/04/24 20:13:00 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	is_redirection(char *str)
{
	if (ft_strcmp(">>", str) == 0)
		return (1);
	else if (ft_strcmp(">", str) == 0)
		return (2);
	else if (ft_strcmp("<", str) == 0)
		return (3);
	else if (ft_strcmp("<<", str) == 0)
		return (4);
	return (0);
}

int	ft_scan_redirect(t_data *data, int i)
{
	while (data->command[i])
	{
		if (is_redirection(data->command[i]))
			return (i);
		i++;
	}
	return (0);
}

void open_file(t_data *data)
{
	int i = 0;

	if (ft_scan_redirect(data, i + 1))
	{
		i = ft_scan_redirect(data, i + 1);
		(data)->fd = malloc(sizeof(int));
		if (is_redirection(data->command[i]) == 1)
			*data->fd = open(data->command[i + 1], O_WRONLY | O_APPEND);
		else if (is_redirection(data->command[i]) == 2)
		{
			fclose(fopen(data->command[i + 1], "w"));
			*data->fd = open(data->command[i + 1], O_WRONLY);
		}
		else if (is_redirection(data->command[i]) == 3)
			*data->fd = open(data->command[2], O_RDONLY);
		redirection(data);
	}
}

int	parsing(char *rd, t_data **data, char **envp)
{
	int	j = dup(1);
	int x = dup(0);
	int	i = 0;

	*data = malloc(sizeof(t_data));
	if (!rd[0])
		return (0);
	(*data)->command = ft_split(rd, ' ');

	if (!(*data)->command)
		ft_error("malloc");
	while ((*data)->command[i])
		i++;
	open_file(*data);

	(*data)->envp = envp;
	if ((*data)->command && ft_strcmp("exit", (*data)->command[0]) == 0)
		return (-1);
	else if ((*data)->command && ft_strcmp("echo", (*data)->command[0]) == 0)
		echo((*data)->command);
	else if ((*data)->command && ft_strcmp("pwd", (*data)->command[0]) == 0)
		pwd((*data)->command);
	else if ((*data)->command && ft_strcmp("cd", (*data)->command[0]) == 0)
		cd((*data)->command);
	else if ((*data)->command && ft_strcmp("env", (*data)->command[0]) == 0)
		env((*data)->command, envp);
	else if ((*data)->command && ft_strcmp("unset", (*data)->command[0]) == 0)
		unset((*data)->command, envp);
	else if ((*data)->command && ft_strcmp("export", (*data)->command[0]) == 0)
		export((*data)->command, envp);
	else
		ft_command(*data);
	dup2(j, 1);
	dup2(x, 0);
	if (ft_scan_redirect(*data, 1))
		close(*(*data)->fd);
	return (1);
}
