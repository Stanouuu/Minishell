/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:06:46 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/12 16:24:19 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_tokenword(char *str, int *i, t_token **token, t_data *data)
{
	int		j;
	int		len;
	char	*newstr;
	t_pft	tmp;

	j = *i;
	len = 0;
	while (str[j] && ft_isespace(str[j]) == 1)
		j++;
	while (str[j + len] && ft_charnextdoor("<>|\"\'", str[j + len]) == 0
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
		tmp = ft_checkparse((*token)->enu);
		return (ft_strjoinandfree(newstr, tmp(str, i, token, data), 2));
	}
	return (newstr);
}

void	ft_tokenexpandlen(char *str, int *j, int *len)
{
	while (str[*j] && ft_isespace(str[*j]) == 1)
		*j = *j + 1;
	while (str[*j + *len] && ft_charnextdoor("<>|\"\'$", str[*j + *len]) == 0
		&& ft_isespace(str[*j + *len]) == 0)
		*len = *len + 1;
	if (str[*j + *len] == '$')
	{
		*len = *len + 1;
		while (str[*j + *len] && ft_isalnum(str[*j + *len]) == 1
			&& ft_charnextdoor("\"$", str[*j + *len]) == 0
			&& ft_isespace(str[*j + *len]) == 0)
			*len = *len + 1;
	}
}

char	*ft_tokenexpand(char *str, int *i, t_token **token, t_data *data)
{
	int		j;
	int		len;
	int		p;
	char	*newstr;
	t_pft	tmp;

	j = *i;
	len = 0;
	ft_tokenexpandlen(str, &j, &len);
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
		tmp = ft_checkparse((*token)->enu);
		return (ft_strjoinandfree(newstr, tmp(str, i, token, data), 2));
	}
	return (newstr);
}

t_pft	ft_checkparse(int n)
{
	t_pft	*tab;

	tab = (t_pft[10]){
		NULL,
	[5] = &ft_tokenword,
	[6] = &ft_tokenexpand,
	[7] = &ft_tokensingle,
	[8] = &ft_tokendouble
	};
	return (tab[n]);
}
