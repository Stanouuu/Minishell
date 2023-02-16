/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:37:56 by sbarrage          #+#    #+#             */
/*   Updated: 2023/02/16 16:32:02 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_command(t_data *data)
{
	pid_t pid;
	char *str;

	pid = fork();
	if (pid == 0)
	{
		if (data->command[0][0] == '.' && data->command[0][1] == '/')
			execv(data->command[0], data->command + 1);
		else
		{
			str = ft_strjoin("/usr/bin/", data->command[0]);
			if (!str)
				ft_error("malloc");
			execv(str, data->command);
			free(str);
		}
		ft_error("malloc");
	}
	else if (pid < 0)
		ft_error("fork");
	else 
	{
		while(wait(NULL) > 0)
		{
		}
	}
	// write(1, "through here", 12);

}