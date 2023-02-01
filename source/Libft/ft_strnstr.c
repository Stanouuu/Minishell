/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:47:20 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/06 20:24:28 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (little[j] == '\0')
		return ((char *)big);
	while (big[i] && i != len)
	{
		while (big[i] == little[j] && i != len)
		{
			if (little[j + 1] == '\0')
				return ((char *)big + (i - j));
			j++;
			i++;
		}
		i = i - j;
		j = 0;
		i++;
	}
	return (0);
}
