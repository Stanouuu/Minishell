/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:06:46 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/10 18:15:58 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dataprocessing.h"

char	*ft_tokenword(char *str, int *i, t_token **token, t_data *data)
{
	int		j;
	int		len;
	char	*newstr;

	j = *i;
	len = 0;
	while (str[j] && ft_isespace(str[j]) == 1)
		j++;
	while (str[j + len] && ft_charnextdoor("<>|\"\'", str[j+ len]) == 0
		&& ft_isespace(str[j + len]) == 0)
		len++;
	newstr = ft_strndup(str + j, len);
	if (!newstr)
		return (NULL);
	*token = (*token)->next;
	*i = j + len;
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

char	*ft_tokenexpand(char *str, int *i, t_token **token, t_data *data)
{
	int		j;
	int		len;
	int		p;
	char	*newstr;

	j = *i;
	len = 0;
	while (str[j] && ft_isespace(str[j])== 1)
		j++;
	while (str[j + len] && ft_charnextdoor("<>|\"\'$", str[j + len]) == 0
		&& ft_isespace(str[j + len]) == 0)
		len++;
	if (str[j + len] == '$')
	{
		len++;
		while (str[j + len] && ft_charnextdoor("\"$", str[j + len]) == 0
		&& ft_isespace(str[j + len]) == 0)
		len++;
	}
	p = ft_findchar(str + j, '$');
	newstr = ft_findinenvp(str + j + p, data->envp, len - p);
	if (!newstr)
		return (NULL);
	if (p > 0)
		newstr = ft_strjoinandfree(ft_strndup(str + j, p), newstr, 2);
	*token = (*token)->next;
	*i = j + len;
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
