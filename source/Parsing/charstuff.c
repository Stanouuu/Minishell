/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charstuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:36:14 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/12 16:24:19 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printsyntax(char c, int *n)
{
	*n = 1;
	ft_putstr_fd("bash: syntax error near unexpected token `", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("'\n", 2);
	g_exitcode = 2;
}

void	printsyntax1(char *str)
{
	ft_putstr_fd(str, 2);
	g_exitcode = 2;
}

int	ft_charnextdoor(char *charset, char c)
{
	int	j;

	j = 0;
	if (!charset)
		return (0);
	while (charset[j])
	{
		if (c == charset[j])
			return (1);
		j++;
	}
	return (0);
}

int	ft_whatsnext(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isespace(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
