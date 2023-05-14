/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:48:11 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/14 13:00:11 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(char **cmd)
{
	char	cwd[256];
	int		i;

	i = 0;
	while (cmd[0][i])
	{
		if (cmd[1])
		{
			write(0, "pwd: too many arguments\n", 24);
			return ;
		}
		i++;
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return ;
	else
		printf("%s\n", cwd);
}
