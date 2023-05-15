/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:28:16 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/15 12:32:31 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_error_tool(t_data *data, char **str)
{
	struct stat	sb;

	if (!*str)
		return (0);
	if (access(*str, X_OK) != 0)
		return (ft_check_error_3_bis(data, *(&str)));
	else if (stat(*str, &sb) == 0)
		return (ft_check_error_3(data, &(*str), sb));
	ft_error("stat");
	g_exitcode = 2;
	return (0);
}

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

int	strcpr(char **tmp, char **str, int i, t_data *data)
{
	char	*join;

	join = ft_strjoin(tmp[i], "/");
	if (!join)
	{
		i = i +1;
		ft_error("malloc");
		g_exitcode = 1;
		return (-1);
	}
	(void)data;
	*str = ft_strjoin(join, data->command[0]);
	if (!*str)
	{
		ft_error("malloc");
		g_exitcode = 1;
		free(join);
		return (-1);
	}
	free(join);
	return (1);
}

char	*getenv_but_better(t_data *data)
{
	int	i;

	i = 0;
	if (!data->envp || !data->envp[0])
		return (0);
	while (data->envp[i])
	{
		if (ft_strncmp(data->envp[i], "PATH=", 5) == 0)
		{
			return (data->envp[i] + 5);
		}
		i++;
	}
	return (0);
}
