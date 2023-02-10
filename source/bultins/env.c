/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:14:18 by sbarrage          #+#    #+#             */
/*   Updated: 2023/02/10 15:37:54 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env(char **cmd, char **envp)
{
	write(1, "h", 1);
	if (cmd[1])
	{
		write(1, "env: too many arguments", 24);
		return ;
	}
	while (*envp)
		printf("%s\n", *envp++);
}