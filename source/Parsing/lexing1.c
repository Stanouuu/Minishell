/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:41:13 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/10 12:59:33 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dataprocessing.h"

/*pour les redirections <*/

t_token	*is_redir_1(char *str, int *i, int *n, t_token *begin)
{
	if ((ft_readsometoken(begin, sinquo) % 2) != 0
		|| (ft_readsometoken(begin, douquo) % 2) != 0)
		return (is_word(str, i, n, begin));
	else if (ft_readlasttoken(begin) <= 4 && ft_readlasttoken(begin) != 0)
		printsyntax(str[*i], n);
	else if (str[*i + 1] && ft_whatsnext(str + *i + 1) == 0)
		printsyntax1(NEWLINEERROR);
	else if (str[*i + 1] && (str[*i + 1] == '>' || str[*i + 1] == '|'))
		printsyntax(str[*i + 1], n);
	else if (str[*i + 1] && str[*i + 1] == '<')
	{
		*i = *i + 1;
		if (is_redir_1_suite(str, i, n) == 1)
			return (ft_tokenadd(begin, heredoc, n));
	}
	else if (str[*i + 1] == '\0')
		printsyntax1(NEWLINEERROR);
	else
		return (ft_tokenadd(begin, infile, n));
	return (ft_tokenclear(begin), NULL);
}

int	is_redir_1_suite(char *str, int *i, int *n)
{
	if (str[*i + 1] && (str[*i + 1] == '<'
			|| str[*i + 1] == '>' || str[*i + 1] == '|'))
		printsyntax(str[*i + 1], n);
	else if (str[*i] == '\0')
		printsyntax(str[*i], n);
	else if ((str[*i + 1] && ft_whatsnext(str + *i + 1) == 0)
		|| str[*i + 1] == '\0')
		printsyntax1(NEWLINEERROR);
	else
		return (1);
	return (0);
}

/*pour les redirections >*/

t_token	*is_redir_2(char *str, int *i, int *n, t_token *begin)
{
	if ((ft_readsometoken(begin, sinquo) % 2) != 0
		|| (ft_readsometoken(begin, douquo) % 2) != 0)
		return (is_word(str, i, n, begin));
	if (ft_readlasttoken(begin) <= 4 && ft_readlasttoken(begin) != 0)
		printsyntax(str[*i], n);
	else if (str[*i + 1] && ft_whatsnext(str + *i + 1) == 0)
		printsyntax1(NEWLINEERROR);
	else if (str[*i + 1] && (str[*i + 1] == '<' || str[*i + 1] == '|'))
		printsyntax(str[*i + 1], n);
	else if (str[*i + 1] && str[*i + 1] == '>')
	{
		*i = *i + 1;
		if (is_redir_2_suite(str, i, n) == 1)
			return (ft_tokenadd(begin, append, n));
	}
	else if (str[*i + 1] == '\0')
		printsyntax1(NEWLINEERROR);
	else
		return (ft_tokenadd(begin, outfile, n));
	return (ft_tokenclear(begin), NULL);
}

int	is_redir_2_suite(char *str, int *i, int *n)
{
	if (str[*i + 1] && (str[*i + 1] == '>'
			|| str[*i + 1] == '<' || str[*i + 1] == '|'))
		printsyntax(str[*i + 1], n);
	else if (str[*i] == '\0')
		printsyntax(str[*i], n);
	else if ((str[*i + 1] && ft_whatsnext(str + *i + 1) == 0)
		|| str[*i + 1] == '\0')
		printsyntax1(NEWLINEERROR);
	else
		return (1);
	return (0);
}

t_token	*is_pip(char *str, int *i, int *n, t_token *begin)
{
	if ((ft_readsometoken(begin, sinquo) % 2) != 0
		|| (ft_readsometoken(begin, douquo) % 2) != 0)
		return (is_word(str, i, n, begin));
	else if (ft_readlasttoken(begin) == 9 || ft_readlasttoken(begin) <= 4)
		printsyntax(str[*i], n);
	else if (str[*i + 1] && ft_whatsnext(str + *i + 1) == 0)
		printsyntax1(NEWLINEERROR);
	else if (str[*i + 1] && (str[*i + 1] == '<'
			|| str[*i + 1] == '>' || str[*i + 1] == '|'))
		printsyntax(str[*i + 1], n);
	else if (str[*i + 1] == '\0')
		printsyntax1(NEWLINEERROR);
	else
		return (ft_tokenadd(begin, pip, n));
	return (ft_tokenclear(begin), NULL);
}
