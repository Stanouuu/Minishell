/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:11:06 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/09 17:05:03 by sbarrage         ###   ########.fr       */
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

int	road(t_data *data)
{
	if (ft_command(data) == -1)
		return (-1);
	while (data)
	{
		close(data->fd[0]);
		data = data->next;
	}
	// if (data->fd[1] != dup(1))
	return (1);
}

// int	parsing(char *rd, t_data **data, char **envp)
// {
// 	int	i = -1;
// 	char *command = "cat";
// 	// char *command2 = "Makefile";
// 	char *fname = "here";

// 	data = malloc(sizeof(t_data *));
// 	(*data) = malloc(sizeof(t_data));
// 	(*data)->files = malloc(sizeof(t_file));
// 	(*data)->files->name = fname;
// 	(*data)->files->enu = outfile;
// 	(*data)->files->next = NULL;
// 	(*data)->command = malloc(sizeof(char *) * 2);
// 	(*data)->command[0] = command;
// 	(*data)->command[1] = NULL;
// /* 	(*data)->command[2] = NULL; */
// 	(*data)->envp = envp;
// 	while((*data)->command[++i])
// 		ft_printf("%s %d\n", (*data)->command[i], i);
// 	i = 0;
// 	if (!rd[0])
// 		return (0);
// 	if (!(*data)->command)
// 		ft_error("malloc");
// 	while ((*data)->command[i])
// 		i++;
// 	if (ft_command(*data) == -1)
// 		return (-1);
// 	if ((*data)->fd[0] != dup(0))
// 		close((*data)->fd[0]);
// 	if ((*data)->fd[1] != dup(1))
// 		close((*data)->fd[1]);
// 	return (1);
// }
