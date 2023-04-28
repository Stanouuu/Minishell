/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:37:56 by sbarrage          #+#    #+#             */
/*   Updated: 2023/04/28 13:42:10 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parent(void)
{
	while (wait(NULL) > 0)
	{
	}
}

void	ft_kid(t_data *data)
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
	exit(0);
}

void	ft_command(t_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		ft_kid(data);
	else if (pid < 0)
		ft_error("fork");
	else
		ft_parent();
}
