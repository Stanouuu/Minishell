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
		free (temp);
		temp = data;
	}
}

t_data	*ft_datacreate(char **envp)
{
	t_data	*data;

	data = calloc(1, sizeof(data));
	if (!data)
		return (NULL);
	data->envp = envp;
	return (data);
}

t_data	*ft_dataadd(t_data *data, char **envp)
{
	t_data	*temp;

	if 	(data == NULL)
		return (ft_datacreate(envp));
	temp = data;
	while (temp->next == NULL)
		temp = temp->next;
	temp->next = ft_datacreate(envp);
	if (temp->next == NULL)
		return (ft_dataclear(data), NULL);
	return (data);
}

char	*ft_tokenword(char *str, int *i, t_token *token, t_data *data)
{
	int		j;
	int		len;
	char	*newstr;

	j = *i;
	len = 0;
	while (str[j] && ft_isespace(str[j]) == 1)
		j++;
	while (str[j + len + 1] && ft_charnextdoor("<>|\"\'", str[j+ len + 1]) == 0
		&& ft_isespace(str[j + len + 1]) == 0)
		len++;
	newstr = ft_strndup(str + j, len);
	if (!newstr)
		return (NULL);
	token = token->next;
	*i = j + len;
	if (token != NULL && token->enu > 4 && token->enu < 9
		&& ft_isespace(str[*i]) == 0)
	{
		if (token->enu == word)
			return (ft_strjoinandfree(newstr, ft_tokenword(str, i, token, data), 2));
		else if (token->enu == expen)
			return (ft_strjoinandfree(newstr, ft_tokenexpand(str, i, token, data), 2));
		else if (token->enu == sinquo)
			return (ft_strjoinandfree(newstr, ft_tokensingle(str, i, token, data), 2));
		else if (token->enu == douquo)
			return (ft_strjoinandfree(newstr, ft_tokendouble(str, i, token, data), 2));
	}
	return (newstr);
}

char	*ft_tokenexpand(char *str, int *i, t_token *token, t_data *data)
{
	int		j;
	int		len;
	int		p;
	char	*newstr;

	j = *i;
	while (str[j] && ft_isespace(str[j])== 1)
		j++;
	p = ft_findchar(str + j, '$');
	newstr = ft_findinenvp(str + p, data->envp, len - p);
	if (!newstr)
		return (NULL);
	if (p > 0)
		newstr = ft_strjoinandfree(ft_strndup(str, p), newstr, 2);
	token = token->next;
	*i = j + len;
	if (token != NULL && token->enu > 4 && token->enu < 9
		&& ft_isespace(str[*i]) == 0)
	{
		if (token->enu == word)
			return (ft_strjoinandfree(newstr, ft_tokenword(str, i, token, data), 2));
		else if (token->enu == expen)
			return (ft_strjoinandfree(newstr, ft_tokenexpand(str, i, token, data), 2));
		else if (token->enu == sinquo)
			return (ft_strjoinandfree(newstr, ft_tokensingle(str, i, token, data), 2));
		else if (token->enu == douquo)
			return (ft_strjoinandfree(newstr, ft_tokendouble(str, i, token, data), 2));
	}
	return (newstr);
}

char	*ft_tokendouble(char *str, int *i, t_token *token, t_data *data)
{
	int	j;

	j = *i;
	while (token->enu != douquo)
	{
		if (ft_isespace(str[j]) != 0)
		{
			ft_strndup(str, /*len des espaces*/);
			j = j + /*len espaces*/;
		}
	}
	
}

char	*ft_tokensingle(char *str, int *i, t_token *token, t_data *data)
{
	int		j;
	int		len;
	char	*newstr;

	j = *i;
	if (str[j + 1])
		j++;
	len = ft_findchar(str + j, '\'');
	newstr = ft_strndup(str +j, len);
	if (!newstr)
		return (NULL);
	while (token && token->enu != sinquo)
		token = token->next;
	token = token->next;
	*i = j + len + 1;//checker le +1 si ledgit ou non
	if (token != NULL && token->enu > 4 && token->enu < 9
		&& ft_isespace(str[*i]) == 0)
	{
		if (token->enu == word)
			return (ft_strjoinandfree(newstr, ft_tokenword(str, i, token, data), 2));
		else if (token->enu == expen)
			return (ft_strjoinandfree(newstr, ft_tokenexpand(str, i, token, data), 2));
		else if (token->enu == sinquo)
			return (ft_strjoinandfree(newstr, ft_tokensingle(str, i, token, data), 2));
		else if (token->enu == douquo)
			return (ft_strjoinandfree(newstr, ft_tokendouble(str, i, token, data), 2));
	}
	return (newstr);
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
		if (ft_tokenredir(temp) == 1)
			res = ft_addredir(str, &i, temp, data);
		else if (ft_tokenpipe(temp) == 1)
			data = ft_dataadd(data, data->envp);
		else
			res = ft_addcommand(str, &i, temp, data);
		if (data == NULL || res == 0)
			return (ft_dataclear(data), NULL);
		temp = temp->next;
	}
	return (data);
}
