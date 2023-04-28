#ifndef DATAPROCESSING_H
# define DATAPROCESSING_H

enum token {
	infile = 1,
	heredoc,
	append,
	outfile,
	word,
	expen,
	sinquo,
	douquo,
	pip,
	none
};

typedef struct		s_token
{
	enum token		enu;
	struct s_token	*next;
}					t_token;

typedef struct		s_file
{
	char			*name;
	struct s_token	*type;
	struct s_file	*next;
}					t_file;

typedef struct		s_data
{
	char			**command;
	char			**envp;
	int				fd[2];
	int				pipe[2];
	struct s_file	*files;
	struct s_data	*next;
}					t_data;

typedef t_token*(*t_pf)(char *, int *, int *, t_token *);

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

t_token	*ft_tokencreate(enum token e);
void	ft_tokenclear(t_token *begin);
t_token	*ft_tokenadd(t_token *begin, enum token e, int *n);
void	ft_putcharfd(char c, int fd);
void	ft_putstrfd(char *str, int fd);
void	printsyntax(char c, int *n);
int		ft_charnextdoor(char *charset, char c);
t_token	*ft_isredir(char *str, t_token *begin, int *n, int *k);
int		ft_isespace(char c);
/*void	ft_lexing(char *str);*/
int		ft_readlasttoken(t_token *begin);
char	*ft_strndup(char *str, int n);
char	*ft_strjoinandfree(char *start, char *end, int n);

#endif
