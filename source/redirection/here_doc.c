/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 08:23:15 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/12 21:58:28 by gfranque         ###   ########.fr       */
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
	str = ft_get_gnl();
	if (!str)
		return (0);
	while (str && ft_strncmp(str, eof, ft_strlen(str)) != 0
		&& g_exitcode != 130)
	{
		ft_putstr_fd(str, fd);
		ft_putstr_fd("\n", fd);
		free(str);
		str = ft_get_gnl();
		if (!str)
			return (0);
	}
	free(str);
	close(fd);
	return (free(eof), 1);
}

char	*ft_get_gnl(void)
{
	int		i;
	char	*str;

	ft_putstr_fd("> ", 1);
	str = get_next_line(0);
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i])
		str[i] = '\0';
	return (str);
}
