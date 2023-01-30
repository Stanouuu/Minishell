/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:12:40 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/09 20:44:56 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	b;

	b = ft_strlen(dest);
	j = 0;
	i = 0;
	if (n == 0 || b >= n)
		return (ft_strlen(src) + n);
	while (dest[i])
		i++;
	while (i + j < n - 1 && src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (b + ft_strlen(src));
}
/*
#include <bsd/string.h>
#include <stdio.h>

int	main()
{
	char string[10] = "h";
	char s[] = "eys";

	printf("real : %li\n", strlcat(string, s, 10));

	char dtring[10] = "h";
	char d[] = "eys";
	printf("stan : %i\n", ft_strlcat(dtring, d, 10));
}*/
