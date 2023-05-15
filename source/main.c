/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:23:38 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/15 09:04:23 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	action(void)
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

char	**cpytab(char **envp)
{
	char	**envpcpy;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	envpcpy = malloc(sizeof(char *) * (i + 1));
	if (!envpcpy)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		envpcpy[i] = ft_strdup(envp[i]);
		if (!envpcpy[i])
		{
			while (i != 0)
				free(envpcpy[--i]);
			return (NULL);
		}
		i++;
	}
	envpcpy[i] = NULL;
	return (envpcpy);
}

void	free_matrix(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		free(envp[i++]);
	free(envp);
}

int	g_exitcode = 0;

int	main(int ac, char **av, char **envp)
{
	int		i;
	char	*str;
	char	**envpcpy[1];
	t_data	*data;

	g_exitcode = 0;
	if (ac != 1 || !av)
		return (0);
	i = 0;
	*envpcpy = cpytab(envp);
	if (!*envpcpy)
		return (1);
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
			data = ft_datacreate(*envpcpy);
			if (!data)
				return (0);
			i = ft_lexing(str, NULL, data);
			*envpcpy = data->envp;
			add_history(str);
			free(str);
			ft_dataclear(data);
		}
	}
	return (free_matrix(*envpcpy), rl_clear_history(), g_exitcode);
}
