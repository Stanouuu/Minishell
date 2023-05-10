/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseurredir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:23:29 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/10 18:23:55 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dataprocessing.h"

int	ft_rediradd(char *str, int *i, t_token **token, t_data *data)
{
	int		enu;
	char	*newstr;
	t_data	*temp;

	if ((*token)->enu == 1)
	{
		enu = (*token)->enu;
		*i = *i + ft_findchar(str + *i, '<');
		*token = (*token)->next;
		if (str[*i + 1])
			*i = *i + 1;
		if ((*token)->enu == word)
			newstr = ft_tokenword(str, i, token, data);
		else if ((*token)->enu == expen)
			newstr = ft_tokenexpand(str, i, token, data);
		else if ((*token)->enu == sinquo)
			newstr = ft_tokensingle(str, i, token, data);
		else if ((*token)->enu == douquo)
			newstr = ft_tokendouble(str, i, token, data);
		if (!newstr)
			return (printf("error redir\n"), 0);
		// printf("infile [%s]\n", newstr);
	}
	else if ((*token)->enu == 2)
	{
		enu = (*token)->enu;
		*i = *i + ft_findchar(str + *i, '<');
		*token = (*token)->next;
		if (str[*i + 1] && str[*i + 2])
			*i = *i + 2;
		if ((*token)->enu == word)
			newstr = ft_tokenword(str, i, token, data);
		else if ((*token)->enu == expen)
			newstr = ft_tokenexpand(str, i, token, data);
		else if ((*token)->enu == sinquo)
			newstr = ft_tokensingle(str, i, token, data);
		else if ((*token)->enu == douquo)
			newstr = ft_tokendouble(str, i, token, data);
		if (!newstr)
			return (printf("error redir\n"), 0);
		// printf("here_doc [%s]\n", newstr);
	}
	else if ((*token)->enu == 3)
	{
		enu = (*token)->enu;
		*i = *i + ft_findchar(str + *i, '>');
		*token = (*token)->next;
		if (str[*i + 1] && str[*i + 2])
			*i = *i + 2;
		if ((*token)->enu == word)
			newstr = ft_tokenword(str, i, token, data);
		else if ((*token)->enu == expen)
			newstr = ft_tokenexpand(str, i, token, data);
		else if ((*token)->enu == sinquo)
			newstr = ft_tokensingle(str, i, token, data);
		else if ((*token)->enu == douquo)
			newstr = ft_tokendouble(str, i, token, data);
		if (!newstr)
			return (printf("error redir\n"), 0);
		// printf("append [%s]\n", newstr);
	}
	else if ((*token)->enu == 4)
	{
		enu = (*token)->enu;
		*i = *i + ft_findchar(str + *i, '>');
		*token = (*token)->next;
		if (str[*i + 1])
			*i = *i + 1;
		if ((*token)->enu == word)
			newstr = ft_tokenword(str, i, token, data);
		else if ((*token)->enu == expen)
			newstr = ft_tokenexpand(str, i, token, data);
		else if ((*token)->enu == sinquo)
			newstr = ft_tokensingle(str, i, token, data);
		else if ((*token)->enu == douquo)
			newstr = ft_tokendouble(str, i, token, data);
		if (!newstr)
			return (printf("error redir\n"), 0);
		// printf("outfile [%s]\n", newstr);
	}
	// free(newstr);
	temp = data;
	while (temp->next != NULL)
		temp = temp->next;
	temp->files = ft_fileadd(newstr, enu, temp->files);
	return (1);
}
