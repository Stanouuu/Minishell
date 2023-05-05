/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:14:18 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/05 19:31:29 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	env(char **cmd, char **envp)
{
	if (cmd[1])
	{
		ft_printf("env: '%s': %s\n", cmd[1], strerror(ENOENT));
		return ;
	}
	while (*envp)
	{
		if (has_equal(*envp))
			printf("%s\n", *envp++);
	}
}
