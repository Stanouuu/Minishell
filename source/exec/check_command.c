/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:52:39 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/08 19:32:50 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_slash(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_error_3_bis(t_data *data, char **str)
{
	if (has_slash(data->command[0]) == 1)
	{
		*str = ft_strjoin("Minishell :", data->command[0]);
		if (!*str)
		{
			ft_error("malloc");
			g_exitcode = 1;
			return (-1);
		}
		ft_error(*str);
		free(*str);
	}
	else
	{
		ft_printf("%s: command not found\n", data->command[0]);
		free(*str);
		g_exitcode = 127;
	}
	*str = NULL;
	return (0);
}

int	ft_check_error_3(t_data *data, char **str, struct stat sb)
{
	if (S_ISDIR(sb.st_mode))
	{
		errno = EISDIR;
		*str = ft_strjoin("Minishell: ", data->command[0]);
		if (!*str)
		{
			ft_error("malloc");
			g_exitcode = 1;
			return (-1);
		}
		ft_error("Minishell: ");
		free(*str);
		*str = NULL;
		g_exitcode = 126;
		return (0);
	}
	return (1);
}

int	ft_check_error_2(t_data *data, char **str)
{
	struct stat	sb;

	if (has_slash(data->command[0]) == 1)
		*str = data->command[0];
	else
		*str = ft_strjoin("/usr/bin/", data->command[0]);
	if (!*str)
	{
		ft_error("malloc");
		g_exitcode = 1;
		return (-1);
	}
	if (access(*str, X_OK) != 0)
		return (ft_check_error_3_bis(data, *(&str)));
	else if (stat(*str, &sb) == 0)
		return (ft_check_error_3(data, &(*str), sb));
	else
	{
		free(str);
		ft_error("stat");
		g_exitcode = 2;
		return (0);
	}
	free(str);
	return (1);
}

int	ft_check_error(t_data *data, char **str)
{
	if (!data->command[0][0])
	{
		ft_printf("%s: command not found here\n", data->command[0]);
		g_exitcode = 127;
		return (0);
	}
	if (data->command[0][0] == '.' && data->command[0][1] == '/')
	{
		if (access(data->command[0], X_OK) != 0)
		{
			*str = ft_strjoin("Minishell: ", data->command[0]);
			if (!str)
			{
				g_exitcode = 1;
				ft_error("malloc");
				return (-1);
			}
			ft_error(*str);
			free(*str);
			*str = NULL;
			return (0);
		}
	}
	else
		return (ft_check_error_2(data, &(*str)));
	return (1);
}
