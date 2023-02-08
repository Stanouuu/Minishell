/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:25:37 by sbarrage          #+#    #+#             */
/*   Updated: 2023/02/08 16:24:38 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"
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

void	echo(char **command);
void	pwd(char **command);
void	cd(char **command);

int		parsing(char *rd, t_data **data);
char	*parsing_2(char *str);


#endif
