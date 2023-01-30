/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:07:39 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/09 20:45:34 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n != 0)
	{
		while (i < n - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

// #include <bsd/string.h>
// #include <stdio.h>

// int	main()
// {	
// 	char	*str = "BBBB";
// 	char	buff1[0xF00];
// 	char	buff2[0xF00];

// 	memset(buff1, 'A', 20);
// 	memset(buff2, 'A', 20);
	// printf("real : %li\n", strlcpy(NULL, NULL, 10));
	// printf("real : %s\n", buff2);
	// printf("real : %s\n", str);
	// str = "BBBB";
	// printf("stan : %i\n", ft_strlcpy(NULL, NULL, 10));
	// printf("stan : %s\n", buff1);
	// printf("stan : %s\n",  str);
// }
