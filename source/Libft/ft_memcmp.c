/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:39:31 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/06 22:09:17 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t n)
{
	size_t			i;
	unsigned char	*string1;
	unsigned char	*string2;

	i = 0;
	string1 = (unsigned char *)pointer1;
	string2 = (unsigned char *)pointer2;
	while (i < n)
	{	
		if (string1[i] != string2[i])
			return (string1[i] - string2[i]);
		i++;
	}
	return (0);
}
/*

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    
	char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};
	printf("%d\n",ft_memcmp(s, sCpy, 4));
	 printf("%d\n\n",memcmp(s, sCpy, 4));

	 printf("%d\n",ft_memcmp(s, s2, 0));
	printf("%d\n\n",memcmp(s, s2, 0));

	 printf("%d\n",ft_memcmp(s, s2, 1));
	 printf("%d\n\n",memcmp(s, s2, 1));

	 printf("%d\n",ft_memcmp(s2, s, 1));
	printf("%d\n\n",memcmp(s2, s, 1));

	printf("%d\n", ft_memcmp(s2, s3, 4));
	 printf("%d\n", memcmp(s2, s3, 4));

	write(1, "\n", 1);

	return (0);
}
*/
