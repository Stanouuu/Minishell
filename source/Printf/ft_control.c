/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:05:36 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/25 21:28:46 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_control(char c, va_list args, int *j)
{
	if (c == 'c')
	{
		ft_putchar((char)va_arg(args, int));
		*j = *j + 1;
	}
	else if (c == 's')
		ft_putstr(va_arg(args, char *), j);
	else if (c == 'p')
		ft_puthex_ads(va_arg(args, unsigned long), "0123456789abcdef", j, 1);
	else if (c == 'd')
		ft_putnbr(va_arg(args, int), j);
	else if (c == 'i')
		ft_putnbr(va_arg(args, int), j);
	else if (c == 'u')
		ft_putnbr_ld(va_arg(args, unsigned int), j);
	else if (c == 'x')
		ft_puthex(va_arg(args, unsigned int), "0123456789abcdef", j);
	else if (c == 'X')
		ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF", j);
}
