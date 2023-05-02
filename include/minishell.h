/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:25:37 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/02 19:20:23 by sbarrage         ###   ########.fr       */
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
#include "dataprocessing.h"

/*##############*/
/*	BULT-INS	*/
/*##############*/

void	echo(char **cmd);
void	pwd(char **cmd);
void	cd(char **cmd);
void	unset(char **cmd, char **envp);
void	export(char **cmd, char **envp);
void	envp_prt_sort(char **envp);
void	env(char **cmd, char **envp);

int		road(t_data *data);
int		ft_command(t_data *data);
int		redirection(t_data *data);
void	controller(t_data *data);
void	redirect(int x, int j);
int		ft_strcmp(char *s1, char *s2);
int		open_file(t_data *data);

int		parsing(char *rd, t_data **data, char **envp);
char	*parsing_2(char *str);

void	ft_error(char *str);

#endif
