/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:19:20 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/10 18:19:56 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dataprocessing.h"

char	*ft_tokendouble(char *str, int *i, t_token **token, t_data *data)
{
	int		j;
	char	*newstr;

	j = *i;
	j = j + ft_findchar(str + j, '\"');
	*token = (*token)->next;
	if (str[j + 1])
		j++;
	newstr = ft_strndup("", ft_strlen(""));
	if (!newstr)
		return (NULL);//avancer jusu'au
	while (*token != NULL && (*token)->enu != douquo)
	{
		if (ft_isespace(str[j]) != 0)
		{
			newstr = ft_strjoinandfree(newstr, ft_strndup(str + j, ft_isespacelen(str + j)), 2);
			if (!newstr)
				return (NULL);
			j = j + ft_isespacelen(str + j);
		}
		*i = j;
		if ((*token)->enu == word)
			newstr = ft_strjoinandfree(newstr, ft_tokenwordindouble(str, i, token), 2);//penser a checker le petit papier sur l amelioration du token word/expand
		else if ((*token)->enu == expen)
			newstr = ft_strjoinandfree(newstr, ft_tokenexpandindouble(str, i, token, data), 2);
		if (!newstr)
			return (NULL);
		j = *i;
	}
	if (*token != NULL && (*token)->enu == douquo)
	{
		if (ft_isespace(str[j]) != 0)
		{
			newstr = ft_strjoinandfree(newstr, ft_strndup(str + j, ft_isespacelen(str + j)), 2);
			if (!newstr)
				return (NULL);
			j = j + ft_isespacelen(str + j);
		}
		*i = j + 1;
		*token = (*token)->next;
	}
	if (*token != NULL && (*token)->enu > 4 && (*token)->enu < 9
		&& ft_isespace(str[*i]) == 0)
	{
		if ((*token)->enu == word)
			return (ft_strjoinandfree(newstr, ft_tokenword(str, i, token, data), 2));
		else if ((*token)->enu == expen)
			return (ft_strjoinandfree(newstr, ft_tokenexpand(str, i, token, data), 2));
		else if ((*token)->enu == sinquo)
			return (ft_strjoinandfree(newstr, ft_tokensingle(str, i, token, data), 2));
		else if ((*token)->enu == douquo)
			return (ft_strjoinandfree(newstr, ft_tokendouble(str, i, token, data), 2));
	}
	return (newstr);	
}

char	*ft_tokensingle(char *str, int *i, t_token **token, t_data *data)
{
	int		j;
	int		len;
	char	*newstr;

	j = *i;
	j = j + ft_findchar(str + j, '\'');
	*token = (*token)->next;
	if (str[j + 1])
		j++;
	len = ft_findchar(str + j, '\'');
	newstr = ft_strndup(str +j, len);
	if (!newstr)
		return (NULL);
	while (*token && (*token)->enu != sinquo)
		*token = (*token)->next;
	*token = (*token)->next;
	*i = j + len + 1;
	if (*token != NULL && (*token)->enu > 4 && (*token)->enu < 9
		&& ft_isespace(str[*i]) == 0)
	{
		if ((*token)->enu == word)
			return (ft_strjoinandfree(newstr, ft_tokenword(str, i, token, data), 2));
		else if ((*token)->enu == expen)
			return (ft_strjoinandfree(newstr, ft_tokenexpand(str, i, token, data), 2));
		else if ((*token)->enu == sinquo)
			return (ft_strjoinandfree(newstr, ft_tokensingle(str, i, token, data), 2));
		else if ((*token)->enu == douquo)
			return (ft_strjoinandfree(newstr, ft_tokendouble(str, i, token, data), 2));
	}
	return (newstr);
}
