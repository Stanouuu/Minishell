/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:46:20 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/12 16:24:19 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*is_quote(char *str, int *i, int *n, t_token *begin)
{
	if (str[*i] == 39)
	{
		if ((ft_readsometoken(begin, douquo) % 2) != 0)
			return (is_word(str, i, n, begin));
		else if (ft_charnextdoor(str + *i + 1, str[*i])
			|| (ft_readsometoken(begin, sinquo) % 2) != 0)
			return (ft_tokenadd(begin, sinquo, n));
	}
	else if (str[*i] == 34)
	{
		if ((ft_readsometoken(begin, sinquo) % 2) != 0)
			return (is_word(str, i, n, begin));
		else if (ft_charnextdoor(str + *i + 1, str[*i])
			|| (ft_readsometoken(begin, douquo) % 2) != 0)
			return (ft_tokenadd(begin, douquo, n));
	}
	return (ft_tokenadd(begin, none, n));
}

t_token	*is_expandindouble(char *str, int *i, int *n, t_token *begin)
{
	int	l;

	l = 0;
	if (str[*i] != '$')
	{
		while (str[*i + l + 1] && ft_charnextdoor("\"$", str[*i + l + 1]) == 0
			&& ft_isespace(str[*i + l + 1]) == 0)
			l++;
		l++;
	}
	while (str[*i + l + 1] && ft_isalnum(str[*i + l + 1]) == 1
		&&ft_charnextdoor("\"$", str[*i + l + 1]) == 0
		&& ft_isespace(str[*i + l + 1]) == 0)
		l++;
	*i = *i + l;
	return (ft_tokenadd(begin, expen, n));
}

t_token	*is_wordindouble(char *str, int *i, int *n, t_token *begin)
{
	int	l;

	l = 0;
	if (str[*i] == '$' )
		return (is_expandindouble(str, i, n, begin));
	while (str[*i + l + 1] && str[*i + l + 1] != '\"'
		&& ft_isespace(str[*i + l + 1]) == 0)
	{
		if (str[*i + l + 1] == '$')
			return (is_expandindouble(str, i, n, begin));
		l++;
	}
	*i = *i + l;
	return (ft_tokenadd(begin, word, n));
}
