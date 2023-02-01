/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:47:09 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/06 19:01:34 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *arr, int c, size_t n)
{
	size_t		i;
	char		*str;

	str = (char *)arr;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	char str1[10] = "qwertyuiop";
	char str2[10] = "0123456789";

	ft_memset(str2, 48, 10);
	memset(str1, 48, 10);
	printf("%s\n",str1);
	printf("\n%i",strlen(str1));
}*/
