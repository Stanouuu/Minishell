/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 23:28:46 by sbarrage          #+#    #+#             */
/*   Updated: 2022/06/01 15:25:31 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buf[1024][BUFFER_SIZE + 1];
	char		*str;
	int			i;

	i = 1;
	str = NULL;
	if (0 > fd || fd > 1023 || BUFFER_SIZE < 1)
		return (NULL);
	if (*buf[fd])
	{
		ft_copy_buf(buf[fd]);
		str = ft_strjoin(str, buf[fd]);
	}
	while (i > 0 && ft_test_line(str))
	{
		i = read(fd, buf[fd], BUFFER_SIZE);
		if (i < 1 && str && *str)
			return (str);
		buf[fd][i] = '\0';
		str = ft_strjoin(str, buf[fd]);
	}
	if (!*str)
		return (ft_nes(str));
	return (ft_sep_line(str));
}

char	*ft_nes(char *str)
{
	free(str);
	return (NULL);
}

char	*ft_sep_line(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	while (str[i] && (str[i] != '\n' ))
		i++;
	if (str[i] == '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (dest);
	i = 0;
	while (str[i] && str[i] != '\n' )
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		dest[i] = str[i];
		i++;
	}
	free(str);
	dest[i] = '\0';
	return (dest);
}
