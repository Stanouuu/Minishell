/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:11:06 by sbarrage          #+#    #+#             */
/*   Updated: 2023/02/21 17:43:12 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char	*ft_close_wrd(char *str, int k)
// {
// 	char	*r2d2;
// 	char	*res;

// 	r2d2 = readline("> ");
// 	res = ft_strjoin("\n", r2d2);
// 	free(r2d2);
// 	r2d2 = res;
// 	res = ft_strjoin(str, r2d2);
// 	free(r2d2);
// 	if (k == -1)
// 		free(str);
// 	return (res);
// }

// char	*parsing_2(char *str)
// {
// 	int		i;
// 	int		j;
// 	int		h;
// 	int		k;
// 	char	*res;

// 	i = 0;
// 	j = 0;
// 	h = 0;
// 	k = 0;
// 	res = ft_calloc(sizeof(char), ft_strlen(str) + 1);
// 	if (!res)
// 		return (NULL);
// 	while (str[i])
// 	{
// 		if ((j == 0 || j == str[i]) && (str[i] == '"' || str[i] == '\''))
// 		{
// 			if (j == 0)
// 				j = str[i];
// 			else
// 				j = 0;
// 			i++;
// 		}
// 		else
// 		{
// 			res[h] = str[i];
// 			h++;
// 			i++;
// 		}
// 		while (j != 0 && !str[i])
// 		{
// 			str = ft_close_wrd(str, k);
// 			free(res);
// 			res = ft_calloc(sizeof(char), ft_strlen(str) + 1);
// 			if (!str || !res)
// 				return (NULL);
// 			i = 0;
// 			h = 0;
// 			j = 0;
// 			k = -1;
// 		}
// 	}
// 	if (k == -1)
// 		free(str);
// 	return (res);
// }

int	parsing(char *rd, t_data **data, char **envp)
{
	int	j = dup(1);
	int	i = 0;

	*data = malloc(sizeof(t_data));
	if (!rd[0])
		return (0);
	(*data)->command = ft_split(rd, ' ');

	if (!(*data)->command)
		ft_error("malloc");
	while ((*data)->command[i])
		i++;
	if (i > 2)
	{
		ft_printf("%d\n", i);
		(*data)->fd = malloc(sizeof(int));
		if (ft_strncmp(">>", (*data)->command[2], 3) == 0)
		{
			*(*data)->fd = open((*data)->command[3], O_WRONLY | O_APPEND);
		}
		else
		{
			write(1, "\n\n\n\nh\n\n\n",8);
			fclose(fopen((*data)->command[3], "w"));
			*(*data)->fd = open((*data)->command[3], O_WRONLY);
		}
		controller(data);
	}
	(*data)->envp = envp;
	
	// if ((*data)->pepe)
	if ((*data)->command && strncmp("exit", (*data)->command[0], 5) == 0)
		return (-1);
	else if ((*data)->command && strncmp("echo", (*data)->command[0], 5) == 0)
		echo((*data)->command);
	else if ((*data)->command && strncmp("pwd", (*data)->command[0], 4) == 0)
		pwd((*data)->command);
	else if ((*data)->command && strncmp("cd", (*data)->command[0], 3) == 0)
		cd((*data)->command);
	else if ((*data)->command && strncmp("env", (*data)->command[0], 4) == 0)
		env((*data)->command, envp);
	else if ((*data)->command && strncmp("unset", (*data)->command[0], 6) == 0)
		unset((*data)->command, envp);
	else if ((*data)->command && strncmp("export", (*data)->command[0], 8) == 0)
		export((*data)->command, envp);
	else
		ft_command(*data);
	if (i > 2)
	{
		dup2(j, 1);
		close(*(*data)->fd);
	}
	return (1);
}