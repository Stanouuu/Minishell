/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:48:11 by sbarrage          #+#    #+#             */
/*   Updated: 2023/01/30 14:14:05 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pwd(char *rd)
{
	char cwd[256];
	int	i;

	i = 3;
	while (rd[i])
	{
		if (rd[i] != ' ')
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