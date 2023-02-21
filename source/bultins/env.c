/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:14:18 by sbarrage          #+#    #+#             */
/*   Updated: 2023/02/17 12:37:38 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env(char **cmd, char **envp)
{
	if (cmd[1])
	{
		ft_printf("env: '%s': %s\n", cmd[1], strerror(ENOENT));
		return ;
	}
	while (*envp)
		printf("%s\n", *envp++);
}
