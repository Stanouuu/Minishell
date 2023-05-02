/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataprocessing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:50:22 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/02 18:50:08 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dataprocessing.h"

t_token	*ft_tokencreate(enum token e)
{
	t_token	*token;

	token = calloc(1, sizeof(t_token));
	if (!token)
		return (NULL);
	token->enu = e;
	token->next = NULL;
	return (token);
}

void	ft_tokenclear(t_token *begin)
{
	t_token *temp;

	temp = begin;
	if (!begin)
		return ;
	while (begin->next != NULL)
	{
		if (temp->enu == 1)
			printf("token is a infile redirection\n");
		else if (temp->enu == 2)
			printf("token is a here_doc\n");
		else if (temp->enu == 3)
			printf("token is a append redirection\n");
		else if (temp->enu == 4)
			printf("token is a outfile redirection\n");
		else if (temp->enu == 5)
			printf("token is a word\n");
		else if (temp->enu == 6)
			printf("token is a expension\n");
		else if (temp->enu == 7)
			printf("token is a single quote\n");
		else if (temp->enu == 8)
			printf("token is a double quote\n");
		else if (temp->enu == 9)
			printf("token is a pipe\n");
		else if (temp->enu == 10)
			printf("token is a none\n");
		begin = begin->next;
		free(temp);
		temp = begin;
	}
	if (temp->enu == 1)
		printf("token is a infile redirection\n");
	else if (temp->enu == 2)
		printf("token is a here_doc\n");
	else if (temp->enu == 3)
		printf("token is a append redirection\n");
	else if (temp->enu == 4)
		printf("token is a outfile redirection\n");
	else if (temp->enu == 5)
		printf("token is a word\n");
	else if (temp->enu == 6)
		printf("token is a expension\n");
	else if (temp->enu == 7)
		printf("token is a single quote\n");
	else if (temp->enu == 8)
		printf("token is a double quote\n");
	else if (temp->enu == 9)
		printf("token is a pipe\n");
	else if (temp->enu == 10)
		printf("token is a none\n");
	free(temp);
	return ;
}

t_token	*ft_tokenadd(t_token *begin, enum token e, int *n)
{	
	t_token	*token;

	*n = 1;
	if (begin == NULL)
		return (ft_tokencreate(e));
	token = begin;
	while (token->next != NULL)
		token = token->next;
	token->next = ft_tokencreate(e);
	if (token->next == NULL)
		return (ft_tokenclear(begin), NULL);
	return (begin);
}

void	ft_putcharfd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}

void	ft_putstrfd(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		ft_putcharfd(str[i], fd);
		i++;
	}
	return ;
}

void	printsyntax(char c, int *n)
{
	*n = 1;
	ft_putstrfd("bash: syntax error near unexpected token `", 2);
	ft_putcharfd(c, 2);
	ft_putstrfd("'\n", 2);	
}

int	ft_charnextdoor(char *charset, char c)
{
	int	j;

	j = 0;
	if (!charset)
		return (0);
	while (charset[j])
	{
		if (c == charset[j])
			return (1);
		j++;
	}
	return (0);
}

int	ft_isespace(char c)
{
	if (9 <= c && c <= 13)
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int	ft_whatsnext(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isespace(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

/*
t_token	*ft_isredir(char *str, t_token *begin, int *n, int *k)//faire un check a la fin du lexing pour checker si il y a bien un mot apres la redir et pas deux redirs ou une redir et rien apres
{
	int	i;//plutot faire un while et juste voir les caracteres qui poppent comme ca il est plus simple d afficher la syntax error
	int	j;

	i = 0;
	j = 0;
	while (str[*k + i + j] && str[*k + i + j] == '<')
		i++;
	while (str[*k + i + j] && str[*k + i + j] == '>')
		j++;
	while (str[*k + i + j] && str[*k + i + j] == '<')
		i++;
	while (str[*k + i + j] && str[*k + i + j] == '>')
		j++;
	if ((i != 0 && j != 0) || i > 2 || j > 2)
		return (printsyntax(str), NULL);
	*k = *k + i + j;
	return (ft_tokenadd(begin, redir, n));
}

//ET SI JE FAIS UN TABLEAU DE POINTEURS SUR FONCTIONS ???? CE SERA SUREMENT PLUS ADAPTE ET PLUS SIMPLE A METTRE EN PLACE VU QUE LES ERREURS AU NIVEAU DU LEXING SONT FACILE A TROUVER ET ENSUITE UNE RELECTURE DU LEXEUR PERMETTRA D AUTRES ERREURS QUOIQUE SI IL Y A DES ERREURS A RETROUVER DANS LA CHAINE CE SERA RELOU DU COUP PREVOIR CA AU MOMENT DE CREER UN NOUVEAU MAYON DEVRAIT ETRE UNE BONNE IDEE. VOILA VOILA.



ft_isword()

ft_isexpend()

ft_issinglequote()

ft_isdoublequote()

ft_ispipe()

void	ft_lexing(char *str)
{
	t_token	*begin;
	t_token	*temp;
	int i;
	int	n;

	i = 0;
	n = 0;
	begin = NULL;
	if (!str)
		return ;
	//printf("a 1 b 2 c 3 d 4 e 5 f 6\n");
	while (str[i])
	{
		if (ft_isespace(str[i]) == 1)
			i++;
		else if (str[i] == '<' || str[i] == '>')
			begin = ft_isredir(str, begin, &n, &i);
		else if (str[i] == 'c')
			begin = ft_tokenadd(begin, 3, &n);
		else if (str[i] == 'd')
			begin = ft_tokenadd(begin, 4, &n);
		else if (str[i] == 'e')
			begin = ft_tokenadd(begin, 5, &n);
		else if (str[i] == 'f')
			begin = ft_tokenadd(begin, 6, &n);
		else
		{
			printf("autre caractere\n");
			fflush;
			i++;
		}
		if (n != 0 && begin == NULL)
			return ;
		
	}
	temp = begin;
	while (temp != NULL)
	{
		printf("token %d\n", temp->enu);
		fflush;
		temp = temp->next;
	}
	ft_tokenclear(begin);
	return ;
}

ft_dataprocessing(char *str)
{
	t_token	*token;

	token = ft_lexing(str);
	if (!token)
		return ;
	
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Bad number of arguments\n");
		ac++;
		return (0);
	}
	ft_lexing(av[1]);
	return (0);
}


*/

// ft_insingle(char *str, t_token *begin);

// // t_token	*ft_tokenadd(t_token *begin, enum token e, int *n)

// t_token	*ft_isinquote(char *str, t_token *begin, enum token e, int *n)
// {
// 	if (ft_insingle(str, begin) == 1)
// 		return (ft_tokenadd(begin, word, n));
// 	if (ft_indouble(str, begin) == 1)
// 		return (ft_tokenadd(begin, word, n));
// 	return (NULL);
// }

int	ft_readsometoken(t_token *begin, enum token e)
{
	int		n;
	t_token	*temp;

	temp = begin;
	n = 0;
	if (temp == NULL)
		return (0);
	while (temp != NULL)
	{
		if (temp->enu == e)
			n++;
		temp = temp->next;
	}
	return (n);
}

int	ft_readlasttoken(t_token *begin)
{
	t_token	*temp;

	temp = begin;
	if (temp == NULL)
		return (0);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp->enu);
}

t_token	*is_word(char *str, int *i, int *n, t_token *begin);

t_token	*is_redir_1(char *str, int *i, int *n, t_token *begin)//pour les redirs <
{
	if ((ft_readsometoken(begin, sinquo) % 2) != 0 || (ft_readsometoken(begin, douquo) % 2) != 0)
		return (is_word(str, i, n, begin));
	else if (ft_readlasttoken(begin) <= 4 && ft_readlasttoken(begin) != 0)
		printsyntax(str[*i], n);
	else if (str[*i + 1] && ft_whatsnext(str + *i + 1) == 0)
		ft_putstrfd("bash: syntax error near unexpected token `newline'\n", 2);
	else if (str[*i + 1] && (str[*i + 1] == '>' || str[*i + 1] == '|'))
		printsyntax(str[*i + 1], n);
	else if (str[*i + 1] &&	str[*i + 1] == '<')
	{
		*i = *i + 1;
		if (str[*i + 1] && (str[*i + 1] == '<'
			|| str[*i + 1] == '>' || str[*i + 1] == '|'))
			printsyntax(str[*i + 1], n);
		else if (str[*i] == '\0')
			printsyntax(str[*i], n);
		else
			return (ft_tokenadd(begin, heredoc, n));
	}
	else if (str[*i + 1] == '\0')
		ft_putstrfd("bash: syntax error near unexpected token `newline'\n", 2);
	else
		return (ft_tokenadd(begin, infile, n));
	return (ft_tokenclear(begin), NULL);
}

t_token	*is_redir_2(char *str, int *i, int *n, t_token *begin)//pour les redirs >
{
	if ((ft_readsometoken(begin, sinquo) % 2) != 0 || (ft_readsometoken(begin, douquo) % 2) != 0)
		return (is_word(str, i, n, begin));
	if (ft_readlasttoken(begin) <= 4 && ft_readlasttoken(begin) != 0)
		printsyntax(str[*i], n);
	else if (str[*i + 1] && ft_whatsnext(str + *i + 1) == 0)
		ft_putstrfd("bash: syntax error near unexpected token `newline'\n", 2);
	else if (str[*i + 1] && (str[*i + 1] == '<' || str[*i + 1] == '|'))
		printsyntax(str[*i + 1], n);
	else if (str[*i + 1] && str[*i + 1] == '>')
	{
		*i = *i + 1;
		if (str[*i + 1] && (str[*i + 1] == '>'
			|| str[*i + 1] == '<' || str[*i + 1] == '|'))
			printsyntax(str[*i + 1], n);
		else if (str[*i] == '\0')
			printsyntax(str[*i], n);
		else
			return (ft_tokenadd(begin, append, n));
	}
	else if (str[*i + 1] == '\0')
		ft_putstrfd("bash: syntax error near unexpected token `newline'\n", 2);
	else
		return (ft_tokenadd(begin, outfile, n));
	return (ft_tokenclear(begin), NULL);
}

t_token	*is_pip(char *str, int *i, int *n, t_token *begin)
{
	if ((ft_readsometoken(begin, sinquo) % 2) != 0 || (ft_readsometoken(begin, douquo) % 2) != 0)
		return (is_word(str, i, n, begin));
	else if (ft_readlasttoken(begin) == 9 || ft_readlasttoken(begin) <= 4)
		printsyntax(str[*i], n);
	else if (str[*i + 1] && ft_whatsnext(str + *i + 1) == 0)
		ft_putstrfd("bash: syntax error near unexpected token `newline'\n", 2);
	else if (str[*i + 1] && (str[*i + 1] == '<'
		|| str[*i + 1] == '>' || str[*i + 1] == '|'))
		printsyntax(str[*i + 1], n);
	else if (str[*i + 1] == '\0')
		ft_putstrfd("bash: syntax error near unexpected token `newline'\n", 2);
	else
		return (ft_tokenadd(begin, pip, n));
	return (ft_tokenclear(begin), NULL);
}


t_token	*is_quote(char *str, int *i, int *n, t_token *begin)
{
	if (str[*i] == 39)
	{
		if ((ft_readsometoken(begin, douquo) % 2) != 0)
			return (is_word(str, i, n, begin));
		else if (ft_charnextdoor(str + *i + 1, str[*i]) || (ft_readsometoken(begin, sinquo) % 2) != 0)
			return (ft_tokenadd(begin, sinquo, n));
	}
	else if (str[*i] == 34)
	{
		if ((ft_readsometoken(begin, sinquo) % 2) != 0)
			return (is_word(str, i, n, begin));
		else if (ft_charnextdoor(str + *i + 1, str[*i]) || (ft_readsometoken(begin, douquo) % 2) != 0)
			return (ft_tokenadd(begin, douquo, n));
	}
	return (ft_tokenadd(begin, none, n));
}

int	is_digit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	is_digitredir(char *str, int i, t_token *begin)
{
	if ((ft_readsometoken(begin, sinquo) % 2) != 0 || (ft_readsometoken(begin, douquo) % 2) != 0)
		return (0);
	while (str[i] && str[i] != '<' && str[i] != '>')
	{
		if (is_digit(str[i]) == 0)
			return (0);
		i++;
	}
	if (str[i] == '<' || str[i] == '>')
		return (1);
	return (0);
}

void	printredirerror(char *str, int i, int *n)
{
	*n = 1;
	ft_putstrfd("bash: syntax error near unexpected token `", 2);
	while (str[i] && is_digit(str[i]) == 1)
	{
		ft_putcharfd(str[i], 2);
		i++;
	}
	ft_putstrfd("'\n", 2);	
}

t_token	*is_word(char *str, int *i, int *n, t_token *begin)
{
	int	e;

	e = 0;
	if (str[*i] == '$')
		e = 1;
	else if (is_digitredir(str, *i, begin) == 1)
	{
		printredirerror(str, *i, n);
		return (ft_tokenclear(begin), NULL);
	}
	while (str[*i + 1] && ft_charnextdoor("<>|\"\'", str[*i + 1]) == 0
		&& ft_isespace(str[*i + 1]) == 0)
	{
		if (str[*i + 1] == '$')
			e = 1;
		*i = *i + 1;
	}
	if (e != 0 && (ft_readsometoken(begin, sinquo) % 2) == 0
		&& ft_readlasttoken(begin) != heredoc)
		return (ft_tokenadd(begin, expen, n));
	else
		return (ft_tokenadd(begin, word, n));
	return (ft_tokenclear(begin), NULL);
}

t_pf	ft_checktoken(char c)
{
	t_pf	*tab;

	tab = (t_pf[128]){
		NULL, 
	['<'] = &is_redir_1,
	['>'] = &is_redir_2,
	['|'] = &is_pip,
	['\''] = &is_quote,
	['\"'] = &is_quote
	};
	if (ft_isespace(c) == 1)
		return (NULL);
	else if (c == '<' || c == '>' || c == '|'
		|| c == '\'' || c == '\"')
		return (tab[(int)c]);
	return (&is_word);
}
/*
int	ft_parse(t_token *begin, t_data data, int *i)
{
	static int	lasttoken;
	int			res;

	if (readlasttoken(begin) == 5)
	{
		if (1 <= lasttoken && lasttoken <= 4)
			res =
		res = 
	}
	if (readlasttoken(begin) == 6)
	{
		if (1 <= lasttoken && lasttoken <= 4)
			res = 
		res = 
	}
	if (readlasttoken(begin) == 7 || readlasttoken(begin) == 8)
		res = 
	lasttoken = readlasttoken(begin);
	return (res);
}
*/
//garder un compteur du dernier token ? afin de savoir toujours ce qu'il y avait avant. Comme ca l'ajout de texte peut etre plus simple. Faire une fonction de check si il y a un quote identique est a venir (usage de static ?)

t_token	*ft_lexing(char *str, t_token *begin, t_data *data)
{
	int		i;
	int		n;
	t_pf	tmp;
	t_data	*temp;//juste le test
	t_file	*filetemp;//juste le test
	
	i = 0;
	n = 0;
	while (str[i])
	{
		tmp = ft_checktoken(str[i]);
		if (tmp != NULL)
			begin = (tmp)(str, &i, &n, begin);
		if (n != 0 && begin == NULL)
			return (NULL);
		i++;
	}
	if (ft_parse(str, begin, data) == NULL)//lancer parse apres le lexing ?
		return (NULL);
	//juste le test
	temp = data;
	while (temp != NULL)
	{
		i = 0;
		while (temp->command[i])
		{
			printf("command[%d] = [%s]\n", i, temp->command[i]);
			i++;
		}
		filetemp = temp->files;
		while (filetemp != NULL)
		{
			printf("redirection [%d] = [%s]\n", filetemp->type, filetemp->name);
			filetemp = filetemp->next;
		}
		temp = temp->next;
	}
	//juste le test
	link(data);
	return (begin);
}

int	main(int ac, char **av, char **envp)
{
	int		i;
	char	*str;
	t_token	*begin;
	t_data	*data;

	if (ac != 1 || !av)
		return (0);
	i = 0;
	while (i != -1)
	{
		str = readline("\033[1;36mminishell> \033[0m");
		if (!str)
			i = -1;
		else
		{
			data = ft_datacreate(envp);
			if (!data)
				return (0);
			begin = NULL;
			begin = ft_lexing(str, begin, data);
			ft_tokenclear(begin);
			add_history(str);
			free(str);
			ft_dataclear(data);
		}
	}
	rl_clear_history();
	return (1);
}














