/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:35:32 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/27 11:44:54 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		j[1];

	if (!str)
		return (-1);
	i = 0;
	*j = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[++i] != '%')
		{
			ft_control(str[i], args, j);
			i++;
		}
		else
		{
			ft_putchar(str[i++]);
			*j = *j + 1;
		}
	}
	return (*j);
}
