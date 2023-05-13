/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandprocessing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:26:58 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/12 19:11:44 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_findinenvp(char *str, char **envp, int len)
{
	int	i;

	i = 0;
	if (!str || !envp)
		return (NULL);
	if (str[1] && ft_strnstr("?", str + 1, len - 1) != NULL)
		return (ft_itoa(g_exitcode));
	while (envp[i])
	{
		if (ft_findchar(envp[i], '=') == len - 1)
		{
			if (ft_strnstr(envp[i], str + 1, len - 1) != NULL)
				return (ft_strndup(envp[i] + len, strlen(envp[i] + len)));
		}
		i++;
	}
	return (ft_strndup("", 1));
}

char	*ft_additionnalfree(char *start, char *end, int n)
{
	if (start && (n == 0 || n == 2))
		free (start);
	if (end && (n == 1 || n == 2))
		free (end);
	return (NULL);
}

char	*ft_strjoinandfree(char *start, char *end, int n)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = -1;
	j = -1;
	if (!start || !end)
		return (ft_additionnalfree(start, end, n));
	len = strlen(start) + strlen(end);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (start[++i])
		str[i] = start[i];
	while (end[++j])
		str[i + j] = end[j];
	if (n == 0 || n == 2)
		free(start);
	if (n == 1 || n == 2)
		free(end);
	return (str);
}

char	*ft_expand(char *str, char **envp, int len)
{
	char	*s;
	int		p;

	p = ft_findchar(str, '$');
	if (p == -1)
	{
		s = ft_calloc(1, sizeof(char));
		if (!s)
			return (NULL);
	}
	else
	{
		s = ft_findinenvp(str + p, envp, len - p);
		if (!s)
			return (NULL);
		if (p > 0)
			s = ft_strjoinandfree(ft_strndup(str, p), s, 2);
	}
	return (s);
}
