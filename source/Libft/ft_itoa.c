/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 05:00:39 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/19 18:28:10 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	size(long int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

unsigned int	square(int n, size_t i)
{
	size_t	h;

	h = 1;
	while (i > 0)
	{
		h = h * n;
		i--;
	}
	return (h);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	n = (long int)n;
	j = size(n);
	str = malloc(sizeof(char) * (j + 1));
	if (!str)
		return (0);
	if (n < 0)
	{
		str[i++] = '-';
		n = n * -1;
		j--;
	}
	while (j > 0)
	{
		str[i] = ((n / square(10, --j)) % 10) + '0' ;
		i++;
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>

// int	main()

// {
// 	printf("%s\n", ft_itoa(2147483648));
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(-10));
// 	printf("%s\n", ft_itoa(10));
// 	printf("%s\n", ft_itoa(2147483647));

// }
