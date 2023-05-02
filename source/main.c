/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:23:38 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/02 19:03:21 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	action()
{
	write(1, "here\n", 5);
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


int	main(int ac, char **av, char **envp)
{
	int		i;
	char	*str;
	t_token	*begin;
	t_data	*data;

	if (ac != 1 || !av)
		return (0);
	i = 0;
	while (i != -1)
	{
		str = readline("\033[1;36mminishell> \033[0m");
		if (!str)
			i = -1;
		else
		{
			data = ft_datacreate(envp);
			if (!data)
				return (0);
			begin = NULL;
			begin = ft_lexing(str, begin, data);
			ft_tokenclear(begin);
			add_history(str);
			free(str);
			ft_dataclear(data);
		}
	}
	rl_clear_history();
	return (1);
}