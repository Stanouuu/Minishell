/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenhandling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:32:47 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/15 13:31:12 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_tokencreate(enum e_token e, int *n)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
	{
		*n = -1;
		return (malloc_error(), NULL);
	}
	token->enu = e;
	token->next = NULL;
	return (token);
}

void	ft_tokenclear(t_token *begin)
{
	t_token	*temp;

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

t_token	*ft_tokenadd(t_token *begin, enum e_token e, int *n)
{	
	t_token	*token;

	*n = 2;
	if (begin == NULL)
		return (ft_tokencreate(e, n));
	token = begin;
	while (token->next != NULL)
		token = token->next;
	token->next = ft_tokencreate(e, n);
	if (token->next == NULL)
		return (ft_tokenclear(begin), NULL);
	return (begin);
}

int	ft_readsometoken(t_token *begin, enum e_token e)
{
	int		n;
	t_token	*temp;

	temp = begin;
	n = 0;
	if (temp == NULL)
		return (0);
	while (temp != NULL)
	{
		if (temp->enu == e)
			n++;
		temp = temp->next;
	}
	return (n);
}

int	ft_readlasttoken(t_token *begin)
{
	t_token	*temp;

	temp = begin;
	if (temp == NULL)
		return (0);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp->enu);
}
