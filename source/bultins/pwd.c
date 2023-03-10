/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:48:11 by sbarrage          #+#    #+#             */
/*   Updated: 2023/02/10 15:38:02 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(char **cmd)
{
	char	cwd[256];
	int		i;

	while (cmd[0][i])
	{
		if (cmd[1])
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
