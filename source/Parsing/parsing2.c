/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:15:43 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/11 16:14:23 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dataprocessing.h"

char	*ft_tokenwordindouble(char *str, int *i, t_token **token)
{
	int		j;
	int		len;
	char	*newstr;

	j = *i;
	len = 0;
	while (str[j] && ft_isespace(str[j]) == 1)
		j++;
	while (str[j + len] && ft_charnextdoor("\"", str[j + len]) == 0
		&& ft_isespace(str[j + len]) == 0)
		len++;
	newstr = ft_strndup(str + j, len);
	if (!newstr)
		return (NULL);
	*token = (*token)->next;
	*i = j + len;
	return (newstr);
}

char	*ft_tokenexpandindouble(char *str, int *i, t_token **token,
	t_data *data)
{
	int		j;
	int		len;
	int		p;
	char	*newstr;

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
	return (newstr);
}
