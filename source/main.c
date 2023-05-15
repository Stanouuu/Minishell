/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:23:38 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/15 22:57:51 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exitcode = 0;

void	action(int signum)
{
	if (signum)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exitcode = 130;
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
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

int	main_2_electric_boogaloo(char *str, int i, char ***envpcpy)
{
	t_data	*data;

		if (!str)
			i = -1;
		else
		{
			data = ft_datacreate(*envpcpy);
			if (!data)
			{
				if (*envpcpy)
					free_matrix(*envpcpy);
				return (rl_clear_history(), g_exitcode);
			}
			i = ft_lexing(str, NULL, data);
			*envpcpy = data->envp;
			add_history(str);

			free(str);
			ft_dataclear(data);
		}
	return (i);
}

int	main(int ac, char **av, char **envp)
{
	int		i;
	char	*str;
	char	**envpcpy[1];

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
		i = main_2_electric_boogaloo(str, i, envpcpy);
	}
	if (*envpcpy)
		free_matrix(*envpcpy);
	return (rl_clear_history(), g_exitcode);
}
