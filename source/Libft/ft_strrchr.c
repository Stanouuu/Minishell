/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:55:06 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/09 01:13:39 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	int	i;

	i = ft_strlen(string);
	while (i >= 0)
	{
		if ((char)string[i] == (char)c)
			return ((char *)string + i);
		i--;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	char *s;


	s = "hello";
	printf("%s\n", strrchr(s, 0));
//	printf("%s\n", ft_strrchr(s, 0));
//	printf("%s\n", strrchr(s, 'l'));
//	printf("%s\n", ft_strrchr(s, 'l'));
//	printf("%s\n", strrchr(s, 't' + 256));
//	printf("%s\n", ft_strrchr(s, 't' + 256));
//		printf("pas NULL\n");
//	else
//		printf("NULL\n");
	if ( ft_strrchr(s, 't' + 256) == strrchr(s, 't' + 256))
//	if ( strrchr(s, 't' + 256))
		printf("OK\n");
	else
		printf("KO\n");
//	if (strrchr(s, 'z'))
//		printf("pas NULL\n");
//	else
//		printf("NULL\n");
	if (ft_strrchr(s, 0) == strrchr(s, 0))
		printf("OK\n");
	else
		printf("KO\n");
//	printf("%s\n", strrchr(s, 'd'));
//	printf("%s\n", ft_strrchr(s, 'd'));
}*/
