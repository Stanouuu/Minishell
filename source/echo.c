/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:18:50 by sbarrage          #+#    #+#             */
/*   Updated: 2023/01/26 16:49:22 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(char *rd)
{
	int	i;
	int	rall;

	rall = 1;
	i = 0;
	while (ft_isalpha(rd[i]) == 1)
	{
		i++;
	}
	while (rd[i] == ' ')
		i++;
	// printf("%d, %d\n", i, ft_strncmp("-n ", rd + i, 3));
	// || strncmp("-n", rd + i, 3) == 0)
	while ((strncmp("-n ", rd + i, 3) == 0 || strncmp("-n", rd + i, 3) == 0) && rd[i])
	{
		rall = 0;
		i += 2;
		while (rd[i] == ' ')
			i++;
	}
	if (rall == 1)
		printf("%s\n", rd + i);
	else 
		printf("%s", rd + i);
}