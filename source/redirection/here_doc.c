/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 08:23:15 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/15 17:10:18 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_here_doc(t_data *data)
{
	int		i;
	t_data	*temp;

	i = 0;
	temp = data;
	while (temp != NULL)
	{
		if (ft_init_here_doc(temp, i) == 0)
			return (0);
		i++;
		temp = temp->next;
	}
	return (1);
}

int	ft_init_here_doc(t_data *data, int i)
{
	int		res;
	char	*name;
	t_file	*temp;

	res = -1;
	temp = data->files;
	while (temp)
	{
		if (temp->type == heredoc)
		{
			name = ft_itoa(i);
			if (!name)
				return (0);
			name = ft_strjoinandfree("/tmp/.", name, 1);
			if (!name)
				return (0);
			res = ft_new_here_doc(temp, name);
			if (res != 1)
				return (0);
		}
		temp = temp->next;
	}
	return (1);
}

int	ft_new_here_doc(t_file *file, char *name)
{
	int		fd;
	char	*eof;
	char	*str;

	eof = file->name;
	file->name = name;
	fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		return (0);
	ft_putstr_fd("> ", 1);
	str = get_next_line(0);
	if (!str)
	{
		malloc_error();
		free(eof);
		return (close(fd), 0);
	}
	if (ft_get_here_doc(str, eof, fd) == 0)
		return (close(fd), 0);
	close(fd);
	return (free(eof), 1);
}

int	ft_get_here_doc(char *str, char *eof, int fd)
{
	while (str && g_exitcode != 130)
	{
		if ((ft_strlen(str) - 1) == ft_strlen(eof)
			&& ft_strncmp(str, eof, ft_strlen(str) - 1) == 0)
			return (free(str), 1);
		ft_putstr_fd(str, fd);
		free(str);
		ft_putstr_fd("> ", 1);
		str = get_next_line(0);
		if (!str)
		{
			free(eof);
			return (malloc_error(), 0);
		}
	}
	return (1);
}
