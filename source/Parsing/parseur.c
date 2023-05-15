/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:20:44 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/15 15:49:38 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_none(char *str, int *i, t_token **token)
{
	*token = (*token)->next;
	while (str[*i] && ft_isespace(str[*i]) == 1)
		*i = *i + 1;
	if (str[*i + 1])
		*i = *i + 1;
	return (1);
}

int	ft_pipeadd(char *str, int *i, t_token **token, t_data *data)
{
	*token = (*token)->next;
	while (str[*i] && ft_isespace(str[*i]) == 1)
		*i = *i + 1;
	if (str[*i + 1])
		*i = *i + 1;
	data = ft_dataadd(data, data->envp);
	if (!data)
		return (0);
	return (1);
}

int	ft_commandadd(char *str, int *i, t_token **token, t_data *data)
{
	char	*newstr;
	t_data	*temp;

	if ((*token)->enu == word)
		newstr = ft_tokenword(str, i, token, data);
	else if ((*token)->enu == expen)
		newstr = ft_tokenexpand(str, i, token, data);
	else if ((*token)->enu == sinquo)
		newstr = ft_tokensingle(str, i, token, data);
	else if ((*token)->enu == douquo)
		newstr = ft_tokendouble(str, i, token, data);
	if (!newstr)
		return (0);
	temp = data;
	while (temp->next != NULL)
		temp = temp->next;
	temp->command = ft_commandcreate(temp->command, newstr);
	if (temp->command == NULL)
		return (0);
	return (1);
}
