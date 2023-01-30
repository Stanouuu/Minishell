/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:23:39 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/10 01:28:19 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*stringdest;
	char		*stringsrc;

	stringdest = (char *)dest;
	stringsrc = (char *)src;
	i = 0;
	if (!dest && !src)
		return (0);
	if (stringdest > stringsrc)
	{
		while (i < n)
		{
			n--;
			stringdest[n] = stringsrc[n];
		}
		return (stringdest);
	}
	while (i != n)
	{
		stringdest[i] = stringsrc[i];
		i++;
	}
	return (stringdest);
}
/*

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int		main(int argc, const char *argv[])
{
	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest;
	int		arg;

	dest = src + 1;
	alarm(5);
	printf("%s", (char *)ft_memmove(dest, src, 8));
//	printf("%s", (char)memmove(dest, src, 8));
	return (0);
}*/
