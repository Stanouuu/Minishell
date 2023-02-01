/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 04:19:45 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/10 03:31:03 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_same(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (is_same(set, s1[i]))
		i++;
	while (is_same(set, s1[j]))
		j--;
	if (j - i + 1 > 0)
	{
		return (ft_substr(s1, i, j - i + 1));
	}
	return (ft_substr("", 1, 1));
}

//  int	main()
//  {
// 	 char *s;
// 	s = ft_strtrim("   xxx   xxx", " x");
//  	printf("%s", s);
// 	free(s);
// }
