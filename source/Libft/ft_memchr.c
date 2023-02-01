/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:36:24 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/06 22:08:20 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *array, int c, size_t n)
{
	char	*string;
	size_t	i;

	i = 0;
	string = (char *)array;
	while (i < n)
	{
		if (string[i] == (char)c)
			return (&string[i]);
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	char s[] = {0, 1, 2 ,3 ,4 ,5};

	printf("%p\n", memchr(s, 0, 0));
	printf("%p\n", ft_memchr(s, 0, 0));

	printf("%p\n", memchr(s, 258, 3));
	printf("%p\n", ft_memchr(s, 258, 3));
//	printf("%p\n", memchr(string, 'j', 5));
//	printf("%p\n", ft_memchr(string, 'j', 5));
}*/
