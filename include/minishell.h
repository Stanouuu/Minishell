/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:25:37 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/01 15:17:49 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <errno.h>
#include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

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
void	echo(char **cmd);
void	pwd(char **cmd);
void	cd(char **cmd);
void	unset(char **cmd, char **envp);
void	export(char **cmd, char **envp);
void	envp_prt_sort(char **envp);
void	env(char **cmd, char **envp);

void	ft_command(t_data *data);
int		is_redirection(char *str);
int		redirection(t_data *data);
void	controller(t_data *data);

int		parsing(char *rd, t_data **data, char **envp);
char	*parsing_2(char *str);

void	ft_error(char *str);

#endif
