/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:32:16 by gfranque          #+#    #+#             */
/*   Updated: 2022/08/24 10:35:00 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
int		ft_no_nl(char *str);
char	*ft_ultimate_read(int fd, char *stat, char *buffer, char *sent);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *start, char *end, int n);
void	ft_strcut(char *sent, char *stat);
void	ft_strcat(char *str, char *start, char *end);

#endif
