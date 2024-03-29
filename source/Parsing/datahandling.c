/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datahandling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:12:37 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/15 16:59:43 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_file	*ft_filecreate(char *str, enum e_token token)
{
	t_file	*file;

	file = ft_calloc(1, sizeof(t_file));
	if (!file)
		return (malloc_error(), NULL);
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
	while (begin != NULL)
	{
		begin = begin->next;
		free(temp->name);
		free(temp);
		temp = begin;
	}
	return ;
}

t_file	*ft_fileadd(char *str, enum e_token token, t_file *begin)
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
	newstrs = ft_calloc(2, sizeof(char *));
	if (!newstrs)
	{
		malloc_error();
		return (free(str), NULL);
	}
	newstrs[0] = str;
	return (newstrs);
}

char	**ft_commandcreate(char **strs, char *str)
{
	int		i;
	char	**newstrs;

	if (!str)
		return (NULL);
	if (!strs)
		return (ft_newcommand(str));
	i = 0;
	while (strs[i])
		i++;
	newstrs = ft_calloc(i + 2, sizeof(char *));
	if (!newstrs)
	{
		free(str);
		ft_free_strs(strs);
		return (malloc_error(), NULL);
	}
	i = -1;
	while (strs[++i])
		newstrs[i] = strs[i];
	newstrs[i] = str;
	free(strs);
	return (newstrs);
}
