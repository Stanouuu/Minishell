/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:48:11 by sbarrage          #+#    #+#             */
/*   Updated: 2023/02/08 14:31:12 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(char **command)
{
	char	cwd[256];
	int		i;

	while (command[0][i])
	{
		if (command[1])
		{
			write(1, "pwd: too many arguments\n", 24);
			return ;
		}
		i++;
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return ;
	else
		printf("%s\n", cwd);
}
