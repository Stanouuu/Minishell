/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:11:06 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/01 17:09:04 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 
int	is_redirection(char *str)
{
	if (ft_strcmp(">>", str) == 0)
		return (1);
	else if (ft_strcmp(">", str) == 0)
		return (2);
	else if (ft_strcmp("<", str) == 0)
		return (3);
	else if (ft_strcmp("<<", str) == 0)
		return (4);
	return (0);
}

int	ft_scan_redirect(t_file *file)
{
	while (file)
	{
		if (file->type != 0)
			return (i);
		i++;
		file->next
	}
	return (0);
} */

int	parsing(char *rd, t_data **data, char **envp)
{
	int	i = 0;

	*data = malloc(sizeof(t_data));
	if (!rd[0])
		return (0);
	(*data)->command[0] = "cd";
	if (!(*data)->command)
		ft_error("malloc");
	while ((*data)->command[i])
		i++;
	(*data)->envp = envp;
	if (ft_command(*data))
		return (-1);
	if ((*data)->fd)
	{
		close(*(*data)->fd);
		free((*data)->fd);
	}
	return (1);
}
