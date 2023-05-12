/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 08:23:15 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/12 14:22:20 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dataprocessing.h"

int	here_doc(t_data *data)
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
		if (temp->enu == here_doc)
		{	name = ft_itoa(i);
			if (!name)
				return (0);
			name = ft_strjoinfree("/temp/.", name, 1);
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
	fd = open(name, O_CREATE | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
		return (0);
	str = get_next_line(0);
	if (!str)
		return (0);
	while (str && ft_strncmp(str, eof, ft_strlen(str) -1) == 0
		&& g_exitcode != 130)
	{
		ft_putstr_fd(str, fd);
		free(str);
		str = get_next_line(0);
		if (!str)
			return (0);
	}
	free(str);
	free(eof);
	close(fd);
	return (1);
}
