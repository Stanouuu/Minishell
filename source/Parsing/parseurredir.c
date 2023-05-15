/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseurredir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:23:29 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/15 16:58:52 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_rediradd(char *str, int *i, t_token **token, t_data *data)
{
	int		enu;
	char	*newstr;
	t_data	*temp;

	enu = (*token)->enu;
	if ((*token)->enu == infile)
		newstr = redir_in(str, i, token, data);
	else if ((*token)->enu == heredoc)
		newstr = redir_here(str, i, token, data);
	else if ((*token)->enu == append)
		newstr = redir_app(str, i, token, data);
	else if ((*token)->enu == outfile)
		newstr = redir_out(str, i, token, data);
	if (newstr == NULL)
		return (ft_putstr_fd("error redir\n", 2), 0);
	temp = data;
	while (temp->next != NULL)
		temp = temp->next;
	temp->files = ft_fileadd(newstr, enu, temp->files);
	if (temp->files == NULL)
		return (free(newstr), 0);
	return (1);
}

char	*redir_in(char *str, int *i, t_token **token, t_data *data)
{
	char	*newstr;

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
		return (NULL);
	return (newstr);
}

char	*redir_here(char *str, int *i, t_token **token, t_data *data)
{
	char	*newstr;

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
		return (NULL);
	return (newstr);
}

char	*redir_app(char *str, int *i, t_token **token, t_data *data)
{
	char	*newstr;

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
		return (NULL);
	return (newstr);
}

char	*redir_out(char *str, int *i, t_token **token, t_data *data)
{
	char	*newstr;

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
		return (NULL);
	return (newstr);
}
