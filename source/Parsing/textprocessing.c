/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textprocessing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:24:49 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/04 16:14:35 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dataprocessing.h"

/*
typedef struct		s_txt
{
	char			*str;
	char			*expand;
	struct s_txt	*next;
}					t_txt;
*/
//creation d'un maillon a assembler plus tard

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little == NULL || strlen(little) == 0)
		return ((char *)big);
	if (big == NULL)
		return (NULL);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
			j++;
		if (j == strlen(little) || j == len)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}


// void	ft_txtclear(t_txt *begin)
// {
// 	t_txt *temp;

// 	if (!begin)
// 		return ;
// 	temp = begin;
// 	while (begin->next != NULL)
// 	{
// 		printf("word [%s]\nexpand [%s]\n", begin->str, begin->expand);
// 		begin = begin->next;
// 		free(temp->str);
// 		free(temp->expand);
// 		free(temp);
// 		temp = begin;
// 	}
// 	printf("word [%s]\nexpand [%s]\n", begin->str, begin->expand);
// 	free(temp->str);
// 	free(temp->expand);
// 	free(temp);
// 	return ;
// }

// int	wordlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (ft_isespace(str[i]) == 1)
// 			return (i);
// 		i++;
// 	}
// 	return (i);
// }

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*s;

	if (!str)
		return (NULL);
	s = calloc(n + 1, sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		s[i] = str[i];
		i++;
	}
	return (s);
}

int	ft_findchar(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_findinenvp(char *str, char **envp, int len)
{
	int	i;

	i = 0;
	if (!str || !envp)
		return (NULL);
	if (ft_strnstr("$?", str + 1, len) != NULL)
		return (ft_itoa(g_exitcode));
	while (envp[i])
	{
		if (ft_findchar(envp[i], '=') == len - 1)
		{
			if (ft_strnstr(envp[i], str + 1, len - 1) != NULL)
				return (ft_strndup(envp[i] + len, strlen(envp[i] + len)));
		}
		i++;
	}
	return (ft_strndup("", 1));
}

char	*ft_additionnalfree(char *start, char *end, int n)
{
	if (start && (n == 0 || n == 2))
		free (start);
	if (end && (n == 1 || n == 2))
		free (end);
	return (NULL);
}

char	*ft_strjoinandfree(char *start, char *end, int n)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = -1;
	j = -1;
	if (!start || !end)
		return (ft_additionnalfree(start, end, n));
	len = strlen(start) + strlen(end);
	str = calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (start[++i])
		str[i] = start[i];
	while (end[++j])
		str[i + j] = end[j];
	if (n == 0 || n == 2)
		free(start);
	if (n == 1 || n == 2)
		free(end);
	return (str);
}

char	*ft_expand(char *str, char **envp, int len)
{
	char	*s;
	int		p;

	p = ft_findchar(str, '$');
	if (p == -1)
	{
		s = calloc(1, sizeof(char));
		if (!s)
			return (NULL);
	}
	else
	{
		s = ft_findinenvp(str + p, envp, len - p);
		if (!s)
			return (NULL);
		if (p > 0)
			s = ft_strjoinandfree(ft_strndup(str, p), s, 2);
	}
	return (s);
}
/*
t_txt	*ft_txtcreate(char *str, int len, char **envp)
{
	t_txt	*text;

	text = calloc(1, sizeof(t_txt));
	if (!text)
		return (NULL);
	text->str = ft_strndup(str, len);
	if (!text->str)
		return (free(text), NULL);
	text->expand = ft_expand(text->str, envp, len);
	if (text->expand == NULL)
	{
		free(text->str);
		free(text);
		return (NULL);
	}
	return (text);
}

t_txt	*ft_txtadd(t_txt *begin, char *str, int len, char **envp)
{
	t_txt	*text;

	if (begin == NULL)
		return (ft_txtcreate(str, len, envp));
	text = begin;
	while (text->next != NULL)
		text = text->next;
	text->next = ft_txtcreate(str, len, envp);
	if (text->next == NULL)
		return (ft_txtclear(begin), NULL);
	return (begin);
}

t_txt	*textprocessing(char *str, int *i, t_txt *begin, char **envp)//just for the words
{
	int		j;
	int		len;

	j = *i;
	len = wordlen(str + j);
	begin = ft_txtadd(begin, str + j, len, envp);
	return (begin);
}
*/






















// int	main(int ac, char **av, char **envp)
// {
// 	t_txt	*begin;
// 	int		i;

// 	if (ac == 1)
// 	{
// 		printf("Please write some arguments\n");
// 		return (1);
// 	}
// 	i = 0;
// 	printf("[%s]\n", av[1]);
// 	while (envp[i])
// 	{
// 		printf("[%s]\n", envp[i]);
// 		i++;
// 	}
// 	i = 0;
// 	begin = NULL;
// 	begin = textprocessing(av[1], &i, begin, envp);
// 	ft_txtclear(begin);
// 	return (0);
// }
