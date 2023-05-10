/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:01:01 by gfranque          #+#    #+#             */
/*   Updated: 2022/06/14 16:51:15 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *start, char *end, int n)
{
	size_t	len;
	char	*str;

	if (ft_strlen(start) == 0 && end == NULL)
		return (NULL);
	len = ft_strlen(start) + ft_strlen(end);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = 0;
	ft_strcat(str, start, end);
	if (n == 1)
		free(start);
	return (str);
}

void	ft_strcut(char *sent, char *stat)
{
	int	i;
	int	j;
	int	len;

	if (ft_no_nl(sent) != 0)
		len = ft_no_nl(sent);
	else
	{
		stat[0] = 0;
		return ;
	}
	i = len;
	j = 0;
	while (sent[i])
	{
		stat[j] = sent[i];
		i++;
		j++;
	}
	stat[j] = '\0';
	sent[len] = '\0';
	return ;
}

void	ft_strcat(char *str, char *start, char *end)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (start)
	{
		while (start[i])
		{
			str[i] = start[i];
			i++;
		}
	}
	if (end)
	{
		while (end[j])
		{
			str[i + j] = end[j];
			j++;
		}
	}
	return ;
}
