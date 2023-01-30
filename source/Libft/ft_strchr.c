/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:19:03 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/07 01:15:03 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((char)s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char *s;

	s = "tripouille";
	printf("%s\n", strchr(s, 't' + 256));
	printf("%s\n", ft_strchr(s, 't'));
	printf("%s\n", strchr(s, 0));
	printf("%s\n", ft_strchr(s, 'l'));
	if (ft_strchr(s, 't' + 256) == strchr(s, 't' + 256))
//	if (ft_strchr(s, 't' + 256))
		printf("OK\n");
	else
		printf("KO\n");
	if (ft_strchr(s, 0))
//	if (ft_strchr(s, 0) == strchr(s, 0))
		printf("OK\n");
	else
		printf("Ko\n");
}*/
