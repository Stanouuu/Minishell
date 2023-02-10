/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:18:50 by sbarrage          #+#    #+#             */
/*   Updated: 2023/02/10 15:37:49 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(char **cmd)
{
	int	i;
	int	j;
	int	rall;

	rall = 0;
	i = 0;
	j = 1;
	if (!cmd[1])
	{
		write(1, "\n", 1);
		return ;
	}
	while (cmd[j] && cmd[j][i] && (strncmp("-n", cmd[j] , 2) == 0))
	{
		i++;
		while (cmd[j][i] == 'n')
			i++;
		if (cmd[j][i] != 0 )
			break ;
		j++;
		rall = i;
		i = 0;
	}
	i = 2;
	while (cmd[j] && cmd[j + 1])
		ft_printf("%s ",cmd[j++]);
	ft_printf("%s",cmd[j]);
	if (rall == 0)
		write(1, "\n", 1);
}
