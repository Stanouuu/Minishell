/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:23:38 by sbarrage          #+#    #+#             */
/*   Updated: 2023/02/01 18:02:15 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	action(void)
{
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

char	*ft_close_wrd(char *str, int k)
{
	char	*r2d2;
	char	*res;

	r2d2 = readline("> ");
	res = ft_strjoin("\n", r2d2);
	free(r2d2);
	r2d2 = res;
	res = ft_strjoin(str, r2d2);
	free(r2d2);
	if (k == -1)
		free(str);
	return (res);
}

char	*parsing_2(char *str)
{
	int		i;
	int		j;
	int		h;
	int		k;
	char	*res;

	i = 0;
	j = 0;
	h = 0;
	k = 0;
	res = ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!res)
		return (NULL);
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
		{
			str = ft_close_wrd(str, k);
			free(res);
			res = ft_calloc(sizeof(char), ft_strlen(str) + 1);
			if (!str || !res)
				return (NULL);
			i = 0;
			h = 0;
			j = 0;
			k = -1;
		}
	}
	if (k == -1)
		free(str);
	return (res);
}

int	parsing(char *rd)
{
	if (rd && rd[0])
		rd = parsing_2(rd);
	while (*rd == ' ')
		rd++;
	if (strncmp("exit", rd, 5) == 0 || strncmp("exit ", rd, 5) == 0)
		return (-1);
	if (strncmp("echo", rd, 5) == 0 || strncmp("echo ", rd, 5) == 0)
		echo(rd);
	if (strncmp("pwd", rd, 4) == 0 || strncmp("pwd ", rd, 4) == 0)
		pwd(rd);
	if (strncmp("cd", rd, 3) == 0 || strncmp("cd  ", rd, 3) == 0)
		cd(rd);
	free(rd);
	return (1);
}

int	main(void)
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
