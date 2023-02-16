/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:25:37 by sbarrage          #+#    #+#             */
/*   Updated: 2023/02/16 16:33:16 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include "libft.h"
#include "ft_printf.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_files
{
	char			*file;
	int				type;//ou un char * avec un text (revoir le lexing)
	struct s_files	*next;
}					t_files;

typedef struct s_data
{
	int				*pipe;
	int				*fd;
	char			**command;
	char			**envp;
	char			**path;
	t_files			*begin;//la liste chainnee des files a ouvrir pour toutes les redirections
}					t_data;

void	echo(char **cmd);
void	pwd(char **cmd);
void	cd(char **cmd);
void	unset(char **cmd, char **envp);
void	export(char **cmd, char **envp);
void	envp_prt_sort(char **envp);
void	env(char **cmd, char **envp);

void	ft_command(t_data *data);

int		parsing(char *rd, t_data **data, char **envp);
char	*parsing_2(char *str);

void	ft_error(char *str);

#endif
