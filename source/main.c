/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:23:38 by sbarrage          #+#    #+#             */
/*   Updated: 2023/01/26 16:37:30 by sbarrage         ###   ########.fr       */
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

int	parsing(char *rd)
{
	if(strncmp("exit", rd, 6) == 0 || strncmp("exit ", rd, 5) == 0)
		return (-1);
	if(strncmp("echo", rd, 6) == 0 || strncmp("echo ", rd, 5) == 0)
		echo(rd);
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
}