/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:52:39 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/12 20:32:10 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_error_3_bis(t_data *data, char **str)
{
	if (has_slash(data->command[0]) == 1)
	{
		*str = ft_strjoin("Minishell :", data->command[0]);
		if (!*str)
			return (malloc_error());
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
			return (malloc_error());
		ft_error("Minishell: ");
		free(*str);
		*str = NULL;
		g_exitcode = 126;
		return (0);
	}
	return (1);
}

int	ft_check_error_21(char **tmp, char **str, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (!tmp)
		return (malloc_error());
	while (tmp[i])
	{
		if (strcpr(tmp, &(*str), i, data) == -1)
			return (free_tab(tmp), -1);
		j = check_error_tool(data, *(&str));
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

int	ft_check_error_2(t_data *data, char **str)
{
	char	**tmp;
	char	*tmpstr;

	if (has_slash(data->command[0]) == 1)
	{
		*str = ft_strdup(data->command[0]);
		if (!*str)
			return (malloc_error());
	}
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
		ft_check_error_21(tmp, &(*str), data);
	}
	return (check_error_tool(data, str));
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
