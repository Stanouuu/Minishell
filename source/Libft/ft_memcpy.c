/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:18:19 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/10 01:27:27 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*strdest;
	char	*strsrc;

	strdest = (char *)dest;
	strsrc = (char *)src;
	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		strdest[i] = strsrc[i];
		i++;
	}
	return (strdest);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	char dest[10] = "1234";
	char src[5] = "bon";

	printf("---ORIGINAL---\ndestination : %s \nsource : %s\n",dest, src);
	ft_memcpy(dest, src, -3);
	printf("---REAL---\ndestination : %s\nsource : %s\n",dest, src);

//	dest = "1234";
//	src = "bon";
}*/
