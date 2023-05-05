/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:18:19 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/05 14:52:36 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error(char *str)
{
	ft_printf("%s: %s\n", str, strerror(errno));
	return (errno);
}

int ft_check_error(t_data *data, char **str)
{
	if (data->command[0][0] == '.' && data->command[0][1] == '/')
	{
		if (access(data->command[0], X_OK) != 0)
		{
			*str = ft_strjoin("Minishell: ", data->command[0]);
			if (!str)
				return (ft_error("malloc"));
			ft_error(*str);
			free(*str);
			*str = NULL;
			return (errno);
		}
	}
	else
	{
		*str = ft_strjoin("/usr/bin/", data->command[0]);
		if (!*str)
			return (ft_error("malloc"));
		if (access(*str, X_OK) != 0)
		{
			free(*str);
			*str = ft_strjoin("Minishell: ", data->command[0]);
			if (!*str)
				return (ft_error("malloc"));
			ft_error(*str);
			free(*str);
			*str = NULL;
			return (errno);
		}
	}
	return (1);
}