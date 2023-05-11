/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textprocessing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:24:49 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/11 22:27:41 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dataprocessing.h"

int	ft_isespace(char c)
{
	if (9 <= c && c <= 13)
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int	ft_isespacelen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] && ft_isespace(str[i]) == 1)
		i++;
	return (i);
}

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*s;

	if (!str)
		return (NULL);
	s = ft_calloc(n + 1, sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		s[i] = str[i];
		i++;
	}
	return (s);
}

int	ft_findchar(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_free_strs(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}
