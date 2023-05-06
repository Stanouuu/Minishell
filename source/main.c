/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:23:38 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/04 16:46:32 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	action()
{
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_exitcode = 130;
}

// ft_free_str(char **str)
// (
// 	str = data->command;
// 	while (str && str[i])
// 	{
// 		free(str[i++]);
// 	}

// )

// void	ft_free_data(t_data *data)
// {
// 	int i;
// 	char **str;

// 	i = 0;
// 	str = data->command;
// 	while (str && str[i])
// 	{
// 		free(str[i++]);
// 	}
// 	free(str);
// 	free (data);
// }

int	g_exitcode = 0;

int	main(int ac, char **av, char **envp)
{
	int		i;
	char	*str;
	t_token	*begin;
	t_data	*data;

	if (ac != 1 || !av)
		return (0);
	i = 0;
	signal(SIGINT, &action);
	signal(SIGQUIT, SIG_IGN);
	while (i != -1)
	{
		str = readline("\033[1;36mminishell> \033[0m");
		if (!str)
		{
			write(1, "out\n", 4);
			i = -1;
		}
		else
		{
			data = ft_datacreate(envp);
			if (!data)
				return (0);
			begin = NULL;
			begin = ft_lexing(str, begin, data);
			add_history(str);
			free(str);
			ft_dataclear(data);
		}
	}
	rl_clear_history();
	return (1);
}