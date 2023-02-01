/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 22:00:46 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/17 18:00:15 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	arr_size(char const *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		if (s[i])
			i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**spdstr;
	int		i;
	int		j;
	int		d;

	d = 0;
	i = 0;
	j = arr_size(s, c);
	spdstr = malloc (sizeof(char *) * (j + 1));
	if (!spdstr)
		return (0);
	while (s[i])
	{
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (i > 0)
			spdstr[d++] = ft_substr(s, j, i - j);
		while (s[i] == c && s[i])
			i++;
	}
	spdstr[d] = NULL;
	return (spdstr);
}
