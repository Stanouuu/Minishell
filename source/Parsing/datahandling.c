/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datahandling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:12:37 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/02 14:54:54 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dataprocessing.h"

t_file	*ft_filecreate(char *str, enum token token)
{
	t_file	*file;
	
	file = calloc(1, sizeof(t_file));
	if (!file)
		return (NULL);
	file->name = str;
	file->type = token;
	file->next = NULL;
	return (file);
}

void	ft_fileclear(t_file *begin)
{
	t_file	*temp;
	
	temp = begin;
	if (!begin)
		return ;
	while (begin->next != NULL)
	{
		begin = begin->next;
		free(temp);
		temp = begin;
	}
	free(temp);
	return ;
}

t_file	*ft_fileadd(char *str, enum token token, t_file *begin)
{
	t_file	*temp;
	
	if (!begin)
		return (ft_filecreate(str, token));
	temp = begin;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = ft_filecreate(str, token);
	if (temp->next == NULL)
		return (ft_fileclear(begin), NULL);
	return (begin);
}

char	**ft_newcommand(char *str)
{
	char	**newstrs;

	if (!str)
		return (NULL);
	newstrs = calloc(2, sizeof(char *));
	if (!newstrs)
		return (free(str), NULL);
	newstrs[0] = str;
	return (newstrs);
}

char	**ft_commandcreate(char **strs, char *str)
{
	int		i;
	char	**newstrs;

	if (!str)
		return (/*free strs*/NULL);//pertinent ?
	if (!strs)
		return (ft_newcommand(str));
	i = 0;
	while (strs[i])
		i++;
	newstrs = calloc(i + 2, sizeof(char *));
	if (!newstrs)
		return (/*freestrs*/NULL);
	i = -1;
	while (strs[++i])
		newstrs[i] = strs[i];
	newstrs[i] = str;
	free(strs);
	return (newstrs);
}
