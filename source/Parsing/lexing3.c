/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:55:21 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/12 16:24:19 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*is_expand(char *str, int *i, int *n, t_token *begin)
{
	int	l;

	l = 0;
	if (str[*i] != '$')
	{
		while (str[*i + l + 1] && ft_isespace(str[*i + l + 1]) == 0
			&& ft_charnextdoor("<>|\"\'$", str[*i + l + 1]) == 0)
			l++;
		l++;
	}
	while (str[*i + l + 1] && ft_isalnum(str[*i + l + 1]) == 1
		&& ft_charnextdoor("<>|\"\'$", str[*i + l + 1]) == 0
		&&ft_isespace(str[*i + l + 1]) == 0)
		l++;
	*i = *i + l;
	return (ft_tokenadd(begin, expen, n));
}

t_token	*is_word(char *str, int *i, int *n, t_token *begin)
{
	int	l;

	l = 0;
	if ((ft_readsometoken(begin, douquo) % 2) == 1)
		return (is_wordindouble(str, i, n, begin));
	if (str[*i] == '$' && ft_readlasttoken(begin) != heredoc
		&& (ft_readsometoken(begin, sinquo) % 2) == 0)
		return (is_expand(str, i, n, begin));
	while (str[*i + l + 1] && ft_isespace(str[*i + l + 1]) == 0
		&& ft_charnextdoor("<>|\"\'", str[*i + l + 1]) == 0)
	{
		if (str[*i + l + 1] == '$' && ft_readlasttoken(begin) != heredoc
			&& (ft_readsometoken(begin, sinquo) % 2) == 0)
			return (is_expand(str, i, n, begin));
		l++;
	}
	*i = *i + l;
	return (ft_tokenadd(begin, word, n));
}
