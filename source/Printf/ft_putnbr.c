/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:13:44 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/26 17:48:21 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *j)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*j = *j + 11;
		return ;
	}
	if (n < 0)
	{
		*j = *j + 1;
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, j);
		ft_putnbr(n % 10, j);
	}
	if (n < 10)
	{
		*j = *j + 1;
		c = '0' + n;
		ft_putchar(c);
	}
}

void	ft_putnbr_ld(unsigned int n, int *j)
{
	char	c;

	if (n > 9)
	{
		ft_putnbr_ld(n / 10, j);
		ft_putnbr_ld(n % 10, j);
	}
	if (n < 10)
	{
		*j = *j + 1;
		c = '0' + n;
		ft_putchar(c);
	}
}
