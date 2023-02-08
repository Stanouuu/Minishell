/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:18:50 by sbarrage          #+#    #+#             */
/*   Updated: 2023/02/08 14:14:09 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(char **command)
{
	int	i;
	int	j;
	int	rall;

	rall = 0;
	i = 0;
	j = 1;
	if (!command[1])
	{
		write(1, "\n", 1);
		return ;
	}
	while (command[j] && command[j][i] && (strncmp("-n", command[j] , 2) == 0))
	{
		i++;
		while (command[j][i] == 'n')
			i++;
		if (command[j][i] != 0 )
			break ;
		j++;
		rall = i;
		i = 0;
	}
	i = 2;
	while (command[j] && command[j + 1])
		ft_printf("%s ",command[j++]);
	ft_printf("%s",command[j]);
	if (rall == 0)
		write(1, "\n", 1);
}
