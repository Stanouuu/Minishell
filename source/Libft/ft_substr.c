/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 03:07:59 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/17 13:47:27 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (((int)ft_strlen(s) - (int)start) < (int)len)
	{
		len = 0;
		if ((int)ft_strlen(s) - (int)start > 0)
			len = ft_strlen(s) - start;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (len == 0)
	{
		str[0] = '\0';
		return (str);
	}
	ft_strlcpy(str, (char *)s + start, len + 1);
	return (str);
}

// #include <stdio.h>

// int	main()
// {
// 	char str[] = "1";
// 	// char *s = ft_substr(str, 8, 9);

// 	printf("%s", ft_substr("", 1, 1));
// 	// free(s);

// }
