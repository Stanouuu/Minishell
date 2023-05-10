/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:52:39 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/10 14:12:45 by sbarrage         ###   ########.fr       */
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

int	check_error_tool(t_data *data, char **str)
{
	struct stat	sb;

	if (access(*str, X_OK) != 0)
		return (ft_check_error_3_bis(data, *(&str)));
	else if (stat(*str, &sb) == 0)
		return (ft_check_error_3(data, &(*str), sb));
	ft_error("stat");
	g_exitcode = 2;
	return (0);
}

int	strcpr(char **tmp, char **str, int i, t_data *data)
{
	*str = ft_strjoin(tmp[i], "/");
	if (!*str)
	{
		ft_error("malloc");
		g_exitcode = 1;
		free(tmp);
		return (-1);
	}
	*str = ft_strjoin(*str, data->command[0]);
	if (!*str)
	{
		ft_error("malloc");
		g_exitcode = 1;
		free(tmp);
		return (-1);
	}
	return (1);
}

int	ft_check_error_2(t_data *data, char **str)
{
	char **tmp;
	int		i;

	i = 0;
	if (has_slash(data->command[0]) == 1)
		*str = data->command[0];
	else
	{
		tmp = ft_split(getenv("PATH"), ':');
		if (!tmp)
		{
			ft_error("malloc");
			g_exitcode = 1;
			free(tmp);
			return (-1);
		}
		while (tmp[i])
		{
			if (strcpr(tmp, *(&str), i, data) == -1)
				return (-1);
			if (check_error_tool(data , *(&str)) == 1)
				return (1);
			else if (check_error_tool(data , *(&str)) == -1)
				return (-1);
			i++;
			free(*str);
		}
		ft_printf("%s: command not found\n", data->command[0]);
		free(tmp);
		g_exitcode = 127;
		return (0);
	}
	if (!*str)
	{
		ft_error("malloc");
		g_exitcode = 1;
		return (-1);
	}
	i = check_error_tool(data, str);
	write(1, "h", 1);
	return (i);
}

int	ft_check_error(t_data *data, char **str)
{
	if (!data->command[0][0])
	{
		ft_printf("%s: command not found here\n", data->command[0]);
		g_exitcode = 127;
		return (0);
	}
	return (ft_check_error_2(data, &(*str)));
}
