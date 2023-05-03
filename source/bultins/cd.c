/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:05:30 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/02 19:46:32 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd(char **cmd)
{
	// char *s;

	// s = NULL;
	ft_printf("%s\n", cmd[1]);
	// printf("%s\n", getcwd(s, 100));
	if (!cmd[1] || ft_strcmp(cmd[1], "~") == 0)
	{
		// ft_printf("%s\n", getenv("HOME"));
		chdir(getenv("HOME"));
	}
	else if (chdir(cmd[1]) == -1)
		ft_printf("cd: %s: %s\n", strerror(errno), cmd[1]);
	// printf("%s\n", getcwd(s, 100));
}
