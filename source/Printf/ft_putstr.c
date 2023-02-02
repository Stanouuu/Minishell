/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:46:36 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/27 11:44:44 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(const char *str, int *j)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		*j = *j + 6;
		return ;
	}
	i = 0;
	while (str[i])
	{
		*j = *j + 1;
		ft_putchar(str[i++]);
	}
}
