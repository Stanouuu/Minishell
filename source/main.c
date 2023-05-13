/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:23:38 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/13 13:02:48 by gfranque         ###   ########.fr       */
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

void	free_pwd(char **envp)
{
	int			i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PWD=", 4) == 0)
			free(envp[i]);
		else if (ft_strncmp(envp[i], "OLDPWD=", 7) == 0)
			free(envp[i]);
		i++;
	}
}

int	g_exitcode = 0;

int	main(int ac, char **av, char **envp)
{
	int		i;
	int		pwd;
	char	*str;
	t_data	*data;

	g_exitcode = 0;
	if (ac != 1 || !av)
		return (0);
	i = 0;
	signal(SIGQUIT, SIG_IGN);
	while (i != -1)
	{
		signal(SIGINT, &action);
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
			i = ft_lexing(str, NULL, data);
			pwd = *(data->pwd);
			add_history(str);
			free(str);

			ft_dataclear(data);
		}
	}
	if (pwd > 0)
		free_pwd(envp);
	return (rl_clear_history(), g_exitcode);
}
