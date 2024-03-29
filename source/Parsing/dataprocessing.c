/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataprocessing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:50:22 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/15 20:20:06 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_digitredir(char *str, int i, t_token *begin)
{
	if ((ft_readsometoken(begin, sinquo) % 2) != 0
		|| (ft_readsometoken(begin, douquo) % 2) != 0)
		return (0);
	while (str[i] && str[i] != '<' && str[i] != '>')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (str[i] == '<' || str[i] == '>')
		return (1);
	return (0);
}

void	printredirerror(char *str, int i, int *n)
{
	*n = 0;
	ft_putstr_fd("bash: syntax error near unexpected token `", 2);
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		ft_putchar_fd(str[i], 2);
		i++;
	}
	ft_putstr_fd("'\n", 2);
}

t_pfl	ft_checktoken(char c)
{
	t_pfl	*tab;

	tab = (t_pfl[128]){
		NULL,
	['<'] = &is_redir_1,
	['>'] = &is_redir_2,
	['|'] = &is_pip,
	['\''] = &is_quote,
	['\"'] = &is_quote
	};
	if (ft_isespace(c) == 1)
		return (NULL);
	else if (c == '<' || c == '>' || c == '|'
		|| c == '\'' || c == '\"')
		return (tab[(int)c]);
	return (&is_word);
}

int	ft_lexing(char *str, t_token *begin, t_data *data)
{
	int		i;
	int		n;
	t_pfl	tmp;

	i = 0;
	n = 1;
	if (ft_strlen(str) == 0)
		return (0);
	while (str[i])
	{
		tmp = ft_checktoken(str[i]);
		if (tmp != NULL)
			begin = (tmp)(str, &i, &n, begin);
		if (n != 1 && begin == NULL)
			return (n);
		i++;
	}
	if (begin == NULL && (ft_isespacelen(str) == (int)ft_strlen(str)))
		return (g_exitcode = 0, 0);
	if (ft_parse(str, begin, data) == NULL)
		return (-1);
	if (ft_here_doc(data) == 0)
		return (-1);
	g_exitcode = 0;
	return (road(data));
}
