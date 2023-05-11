/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:14:18 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/11 19:23:10 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_equal(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '=')
			return (1);
		else
			printf("str[i] : %c\n", str[i]);
		i++;
	}
	return (0);
}

void	env(char **cmd, char **envp)
{
	int	i;

	i = 0;
	if (cmd[1])
	{
		ft_printf("env: '%s': %s\n", cmd[1], strerror(ENOENT));
		return ;
	}
	while (envp[i])
	{
		if (has_equal(envp[i]) == 1)
			printf("%s\n", envp[i]);
		i++;
	}
}
