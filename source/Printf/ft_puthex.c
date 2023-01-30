/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:43:23 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/27 11:45:01 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long n, char *str, int *j)
{
	*j = *j + 1;
	if (n > 15)
		ft_puthex(n / 16, str, j);
	ft_putchar(str[n % 16]);
}

void	ft_puthex_ads(unsigned long n, char *str, int *j, int b)
{
	if (!n)
	{
		write(1, "(nil)", 5);
		*j = *j + 5;
		return ;
	}
	if (b)
	{
		write (1, "0x", 2);
		*j = *j + 2;
	}
	*j = *j + 1;
	if (n > 15)
		ft_puthex_ads(n / 16, str, j, 0);
	ft_putchar(str[n % 16]);
}
