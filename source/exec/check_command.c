/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:52:39 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/11 17:10:57 by sbarrage         ###   ########.fr       */
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
	}
	free(*str);
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
	// free(*str);
	return (1);
}

int	check_error_tool(t_data *data, char **str)
{
	struct stat	sb;

	// ft_printf("%s\n", *str);
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
	char *join;
	
	join = ft_strjoin(tmp[i], "/");
	if (!join)
	{
		ft_error("malloc");
		g_exitcode = 1;
		free(tmp);
		return (-1);
	}
	*str = ft_strjoin(join, data->command[0]);
	free(join);
	if (!*str)
	{
		ft_error("malloc");
		g_exitcode = 1;
		free(tmp);
		return (-1);
	}
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
			// ft_printf("%s\n", data->envp[i] + 5);
			return (data->envp[i] + 5);
		}
		i++;
	}
	return (0);
}

void	free_tab(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

int	ft_check_error_2(t_data *data, char **str)
{
	char **tmp;
	int		i;
	int		j;
	char *tmpstr;

	i = 0;
	if (has_slash(data->command[0]) == 1)
		*str = ft_strdup(data->command[0]);
	else
	{
		tmpstr = getenv_but_better(data);
		if (!tmpstr)
		{
			ft_printf("%s: command not found\n", data->command[0]);
			g_exitcode = 127;
			return (0);
		}
		else
			tmp = ft_split(tmpstr, ':');
		if (!tmp)
		{
			ft_error("malloc");
			g_exitcode = 1;
			return (-1);
		}
		while (tmp[i])
		{
			// if (!*str)
			// 	ft_printf("str still NULL\n");
			// else
			// 	ft_printf("str = to %s\n", *str);
			if (strcpr(tmp, &(*str), i, data) == -1)
				return (free_tab(tmp), -1);
			j = check_error_tool(data , *(&str));
			if (j == 1 || j == -1)
				return (free_tab(tmp), j);
			i++;
			free(*str);

		}
		free_tab(tmp);
		ft_printf("%s: command not found\n", data->command[0]);
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
