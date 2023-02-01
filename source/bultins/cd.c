/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:05:30 by sbarrage          #+#    #+#             */
/*   Updated: 2023/02/01 16:59:36 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	cd(char *rd)
{
	rd += 2;
	printf("%s\n", rd);
	while (*rd && *rd == ' ')
		rd++;
	if (!(*rd))
	{
		chdir(getenv("HOME"));
		return ;
	}
	if (chdir(rd) == -1)
	{
		printf("cd: no such file or directory: %s\n", rd);
	}
}
