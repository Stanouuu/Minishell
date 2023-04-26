/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:23:38 by sbarrage          #+#    #+#             */
/*   Updated: 2023/04/24 19:28:28 by stan             ###   ########.fr       */
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

// ft_free_str(char **str)
// (
// 	str = data->command;
// 	while (str && str[i])
// 	{
// 		free(str[i++]);
// 	}

// )

void	ft_free_data(t_data *data)
{
	int i;
	char **str;

	i = 0;
	str = data->command;
	while (str && str[i])
	{
		free(str[i++]);
	}
	free(str);
	free (data);
}

int	main(int argc, char **argv, char **envp)
{
	char	*rd;
	int		i;
	t_data	*data;

	if (argc > 1 && argv)
		return (-1);
	data = NULL;
	signal(SIGINT, &action);
	signal(SIGQUIT, SIG_IGN);
	i = 0;
	while (i != -1)
	{
		rd = readline("minishell> ");
		if (!rd)
		{
			write(1, "out\n", 4);
			i = -1;
		}
		else if (rd[0])
		{
			i = parsing(rd, &data, envp);
			printf("action = %s %d\n", rd, i);
			ft_free_data(data);
		}
		add_history(rd);
		free(rd);
	}
	rl_clear_history();
	write(1, "exit\n", 5);
}
