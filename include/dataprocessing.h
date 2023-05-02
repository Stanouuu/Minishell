/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataprocessing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:24:52 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/02 18:52:22 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATAPROCESSING_H
# define DATAPROCESSING_H

// enum token {
// 	infile = 1,
// 	heredoc,
// 	append,
// 	outfile,
// 	word,
// 	expen,
// 	sinquo,
// 	douquo,
// 	pip,
// 	none
// };

// typedef struct		s_token
// {
// 	enum token		enu;
// 	struct s_token	*next;
// }					t_token;

// typedef struct		s_file
// {
// 	char			*name;
// 	enum token		type;
// 	struct s_file	*next;
// }					t_file;

// typedef struct		s_data
// {
// 	char			**command;
// 	char			**envp;
// 	int				fd[2];
// 	int				pipe[2];
// 	struct s_file	*files;
// 	struct s_data	*next;
// }					t_data;

typedef t_token*(*t_pf)(char *, int *, int *, t_token *);

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include "minishell.h"

/*######################*/
/*	dataprocessing.c	*/
/*######################*/

t_token	*ft_tokencreate(enum token e);
void	ft_tokenclear(t_token *begin);
t_token	*ft_tokenadd(t_token *begin, enum token e, int *n);
void	ft_putcharfd(char c, int fd);
void	ft_putstrfd(char *str, int fd);
void	printsyntax(char c, int *n);
int		ft_charnextdoor(char *charset, char c);
int		ft_isespace(char c);
int		ft_whatsnext(char *str);
int		ft_readsometoken(t_token *begin, enum token e);
int		ft_readlasttoken(t_token *begin);
t_token	*is_redir_1(char *str, int *i, int *n, t_token *begin);//pour les redirs <
t_token	*is_redir_2(char *str, int *i, int *n, t_token *begin);//pour les redirs >
t_token	*is_pip(char *str, int *i, int *n, t_token *begin);
t_token	*is_quote(char *str, int *i, int *n, t_token *begin);
int		is_digit(char c);
int		is_digitredir(char *str, int i, t_token *begin);
void	printredirerror(char *str, int i, int *n);
t_token	*is_word(char *str, int *i, int *n, t_token *begin);
t_pf	ft_checktoken(char c);
t_token	*ft_lexing(char *str, t_token *begin, t_data *data);

/*######################*/
/*	dataprocessing2.c	*/
/*######################*/

void	ft_dataclear(t_data *data);
t_data	*ft_datacreate(char **envp);
t_data	*ft_dataadd(t_data *data, char **envp);
int		ft_isespacelen(char *str);
char	*ft_tokenword(char *str, int *i, t_token **token, t_data *data);
char	*ft_tokenexpand(char *str, int *i, t_token **token, t_data *data);
char	*ft_tokenwordindouble(char *str, int *i, t_token **token);
char	*ft_tokenexpandindouble(char *str, int *i, t_token **token, t_data *data);
char	*ft_tokendouble(char *str, int *i, t_token **token, t_data *data);
char	*ft_tokensingle(char *str, int *i, t_token **token, t_data *data);
int		ft_rediradd(char *str, int *i, t_token **token, t_data *data);
int		ft_none(char *str, int *i, t_token **token);
int		ft_pipeadd(char *str, int *i, t_token **token, t_data *data);
int		ft_commandadd(char *str, int *i, t_token **token, t_data *data);
t_data	*ft_parse(char *str, t_token *begin, t_data *data);

/*######################*/
/*	textprocessing.c	*/
/*######################*/

char	*ft_strndup(char *str, int n);
int		ft_findchar(char *str, char c);
char	*ft_findinenvp(char *str, char **envp, int len);
char	*ft_additionnalfree(char *start, char *end, int n);
char	*ft_strjoinandfree(char *start, char *end, int n);
char	*ft_expand(char *str, char **envp, int len);

/*######################*/
/*	datahandling.c		*/
/*######################*/

t_file	*ft_filecreate(char *str, enum token token);
void	ft_fileclear(t_file *begin);
t_file	*ft_fileadd(char *str, enum token token, t_file *begin);
char	**ft_newcommand(char *str);
char	**ft_commandcreate(char **strs, char *str);

#endif
