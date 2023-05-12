/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:19:20 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/12 16:57:30 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_tokendouble(char *str, int *i, t_token **token, t_data *data)
{
	char	*newstr;
	t_pft	tmp;

	*i = *i + ft_findchar(str + *i, '\"');
	*token = (*token)->next;
	if (str[*i + 1])
		*i = *i + 1;
	newstr = ft_tokendouble1(str, i, token, data);
	if (newstr == NULL)
		return (NULL);
	newstr = ft_tokendouble2(str, i, token, newstr);
	if (newstr == NULL)
		return (NULL);
	if (*token != NULL && (*token)->enu > 4 && (*token)->enu < 9
		&& ft_isespace(str[*i]) == 0)
	{
		tmp = ft_checkparse((*token)->enu);
		return (ft_strjoinandfree(newstr, tmp(str, i, token, data), 2));
	}
	return (newstr);
}

char	*ft_tokendouble1(char *str, int *i, t_token **token, t_data *data)
{
	char	*newstr;

	newstr = ft_strndup("", ft_strlen(""));
	if (!newstr)
		return (NULL);
	while (*token != NULL && (*token)->enu != douquo)
	{
		if (ft_isespace(str[*i]) != 0)
		{
			newstr = ft_strjoinandfree(newstr, ft_strndup(str + *i,
						ft_isespacelen(str + *i)), 2);
			if (!newstr)
				return (NULL);
			*i = *i + ft_isespacelen(str + *i);
		}
		if ((*token)->enu == word)
			newstr = ft_strjoinandfree(newstr,
					ft_tokenwordindouble(str, i, token), 2);
		else if ((*token)->enu == expen)
			newstr = ft_strjoinandfree(newstr,
					ft_tokenexpandindouble(str, i, token, data), 2);
		if (!newstr)
			return (NULL);
	}
	return (newstr);
}

char	*ft_tokendouble2(char *str, int *i, t_token **token, char *newstr)
{	
	if (*token != NULL && (*token)->enu == douquo)
	{
		if (ft_isespace(str[*i]) != 0)
		{
			newstr = ft_strjoinandfree(newstr, ft_strndup(str + *i,
						ft_isespacelen(str + *i)), 2);
			if (!newstr)
				return (NULL);
			*i = *i + ft_isespacelen(str + *i);
		}
		*i = *i + 1;
		*token = (*token)->next;
	}
	return (newstr);
}

char	*ft_tokensingle(char *str, int *i, t_token **token, t_data *data)
{
	int		j;
	int		len;
	char	*newstr;
	t_pft	tmp;

	j = *i;
	j = j + ft_findchar(str + j, '\'');
	*token = (*token)->next;
	if (str[j + 1])
		j++;
	len = ft_findchar(str + j, '\'');
	newstr = ft_strndup(str + j, len);
	if (!newstr)
		return (NULL);
	while (*token && (*token)->enu != sinquo)
		*token = (*token)->next;
	*token = (*token)->next;
	*i = j + len + 1;
	if (*token != NULL && (*token)->enu > 4 && (*token)->enu < 9
		&& ft_isespace(str[*i]) == 0)
	{
		tmp = ft_checkparse((*token)->enu);
		return (ft_strjoinandfree(newstr, tmp(str, i, token, data), 2));
	}
	return (newstr);
}
