/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:14:14 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/31 23:57:02 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_copy_buf(char *buf)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (buf && buf[i - 1] != '\n' && buf[i])
		i++;
	while (buf && buf[i])
		buf[j++] = buf[i++];
	buf[j] = '\0';
	return (buf);
}

int	ft_test_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	free(s1);
	j = 0;
	while (s2 && s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
