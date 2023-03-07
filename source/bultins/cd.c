/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:05:30 by sbarrage          #+#    #+#             */
/*   Updated: 2023/02/17 12:36:52 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd(char **cmd)
{
	if (!cmd[1])
	{
		chdir(getenv("HOME"));
		return ;
	}
	if (chdir(cmd[1]) == -1)
		ft_printf("cd: %s: %s\n", strerror(errno), cmd[1]);
}
