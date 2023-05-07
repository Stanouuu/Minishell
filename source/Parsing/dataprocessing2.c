/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataprocessing2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:25:06 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/07 14:55:11 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dataprocessing.h"


/*
faire liste de fontions:
	fonction mot -> retourne une string avec le mot avec check si join il faut
	fonction exand ->  retourne l'expand
	fonction single quote -> retourne strndup de la longueur entre les single quote
	fonction double quote -> retourne un assemblage
*/

void	ft_dataclear(t_data *data)
{
	t_data	*temp;

	if (!data)
		return ;
	temp = data;
	while (data != NULL)
	{
		data = data->next;
		if (temp->command != NULL)
			ft_free_strs(temp->command);
		if (temp->files != NULL)
			ft_fileclear(temp->files);
		free (temp);
		temp = data;//penser a free les commandes et free les files
	}
}

t_data	*ft_datacreate(char **envp)
{
	t_data	*data;

	data = calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->envp = envp;
	data->command = NULL;
	data->files = NULL;
	return (data);
}

t_data	*ft_dataadd(t_data *data, char **envp)
{
	t_data	*temp;

	temp = data;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = ft_datacreate(envp);
	if (temp->next == NULL)
		return (ft_dataclear(data), NULL);
	return (data);
}

int	ft_isespacelen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] && ft_isespace(str[i]) == 1)
		i++;
	return (i);
}

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

char	*ft_tokenwordindouble(char *str, int *i, t_token **token)
{
	int		j;
	int		len;
	char	*newstr;

	j = *i;
	len = 0;
	while (str[j] && ft_isespace(str[j]) == 1)
		j++;
	while (str[j + len] && ft_charnextdoor("\"", str[j+ len]) == 0
		&& ft_isespace(str[j + len]) == 0)
		len++;
	newstr = ft_strndup(str + j, len);
	if (!newstr)
		return (NULL);
	*token = (*token)->next;
	*i = j + len;
	return (newstr);
}

char	*ft_tokenexpandindouble(char *str, int *i, t_token **token, t_data *data)
{
	int		j;
	int		len;
	int		p;
	char	*newstr;

	j = *i;
	len = 0;
	while (str[j] && ft_isespace(str[j])== 1)
		j++;
	while (str[j + len] && ft_charnextdoor("\"$", str[j + len]) == 0
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
	return (newstr);
}

char	*ft_tokendouble(char *str, int *i, t_token **token, t_data *data)
{
	int		j;
	char	*newstr;

	j = *i;
	j = j + ft_findchar(str + j, '\"');
	*token = (*token)->next;
	if (str[j + 1])
		j++;
	newstr = ft_strndup("", strlen(""));
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
		return (printf("error command\n"), 0);
	// printf("command [%s]\n", newstr);
	// free(newstr);
	temp = data;
	while (temp->next != NULL)
		temp = temp->next;
	temp->command = ft_commandcreate(temp->command, newstr);
	if (temp->command == NULL)
		return (0);
	return (1);
}

int	ft_checkdata(t_data *data)
{
	char	*newstr;
	t_data	*temp;

	temp = data;
	while (temp != NULL)
	{
		if (temp->command == NULL)
		{
			newstr = ft_strndup("", 0);
			if (!newstr)
				return (0);
			temp->command = ft_commandcreate(temp->command, newstr);
			if (temp->command == NULL)
				return (0);
		}
		temp = temp->next;
	}
	return (1);
}

//gerer le token none !!!!!!!!!!!
t_data	*ft_parse(char *str, t_token *begin, t_data *data)//malloquer le premier data et lui donner l'envp !!!!
{
	int		i;
	int		res;
	t_token	*temp;

	i = 0;
	res = 1;
	temp = begin;
	if (begin == NULL)
		return (NULL);
	while (temp != NULL)
	{
		if (temp->enu >= 1 && temp->enu <= 4)
			res = ft_rediradd(str, &i, &temp, data);
		else if (temp->enu == pip)
			res = ft_pipeadd(str, &i, &temp, data);
		else if(temp->enu == none)
			res = ft_none(str, &i, &temp);//doit avancer de 1 et faire temp = temp->next
		else
			res = ft_commandadd(str, &i, &temp, data);
		if (res == 0)
			return (ft_dataclear(data), NULL);
	}
	ft_checkdata(data);
	ft_tokenclear(begin);
	return (data);
}
