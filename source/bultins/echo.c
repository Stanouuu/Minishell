/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:18:50 by sbarrage          #+#    #+#             */
/*   Updated: 2023/02/01 17:57:37 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	echo(char *rd)
{
	int	i;
	int	rall;

	rall = 0;
	i = 0;
	while (ft_isalpha(rd[i]) == 1)
		i++;
	while (rd[i] == ' ')
		i++;
	while ((strncmp("-n", rd + i, 2) == 0) && rd[i])
	{
		i++;
		while (rd[i] == 'n')
			i++;
		if (rd[i] != '\0' && rd[i] != ' ')
			break ;
		while (rd[i] == ' ')
			i++;
		rall = i;
	}
	if (rall == 0)
		printf("%s\n", rd + i);
	else
		printf("%s", rd + i);
}
