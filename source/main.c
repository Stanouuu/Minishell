/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:23:38 by sbarrage          #+#    #+#             */
/*   Updated: 2023/01/30 16:43:59 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	action()
{
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

char	*ft_close_wrd(char *str, int i)
{
	char *r2d2;
	char *res;

	write(1, "h", 1);
	while (!str[i])
	{
		r2d2 = readline("quote> "); 
		res = ft_strjoin(str, r2d2);
		printf(" quote : %s\n", res, j);
	}
	free(str);
	free(r2d2);
	return (res);
}

char	*parsing_2(char *str)
{
	int		i;
	int		j;
	int		h;
	char	*res;

	i = 0;
	j = 0;
	h = 0;
	res = ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!res)
		return(NULL);
	while (str[i])
	{
		if ((j == 0 || j == str[i]) && (str[i] == '"' || str[i] == '\''))
		{
			if (j == 0)
				j = str[i];
			else 
				j = 0;
			i++;
		}
		else
		{
			res[h] = str[i];
			h++;
			i++;
		}
		while (j != 0 && !str[i])
			res = ft_close_wrd(res, i);
	}
	printf("%s\nj : %d\n", res, j);
	return (res);
}

int	parsing(char *rd)
{
	if (rd && rd[0])
		rd = parsing_2(rd);
	while (*rd == ' ')
		rd++;
	if(strncmp("exit", rd, 5) == 0 || strncmp("exit ", rd, 5) == 0)
		return (-1);
	if(strncmp("echo", rd, 5) == 0 || strncmp("echo ", rd, 5) == 0)
		echo(rd);
	if(strncmp("pwd", rd, 4) == 0 || strncmp("pwd ", rd, 4) == 0)
		pwd(rd);
	if(strncmp("cd", rd, 3) == 0 || strncmp("cd  ", rd, 3) == 0)
		cd(rd);
	return (1);
}

int	main()
{
	char	*rd;
	int		i;

	signal(SIGINT, &action);
	signal(SIGQUIT, SIG_IGN);
	i = 0;
	while (i != -1)
	{
		rd = readline("minishell> ");
		if (!rd)
			i = -1;
		else
			i = parsing(rd);
		printf("action = %s\n", rd);
		add_history(rd);
		free(rd);
	}
	rl_clear_history();
	write(1, "exit\n", 5);
}
