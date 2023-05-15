/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:25:37 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/15 23:30:06 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/stat.h>
# include "libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "dataprocessing.h"

extern int	g_exitcode;

/*##############*/
/*	 BULT-INS	*/
/*##############*/

void	echo(char **cmd);
void	pwd(char **cmd);
int		cd(char **cmd, char **envp);
int		unset(char **cmd, char ***envp);
void	unset_error(char ***envp, int i);
int		export(char **cmd, char ***envp);
int		envp_prt_sort(char **envp);
int		ft_add_env(char **cmd, char ***envp, int j, char **envpcpy);
int		cpytab_to_another(char **envp, char ***envpcpy);
int		conca_export(char **cmd, char ***envp, int j);
int		export_1(char **cmd, char ***envp, int j);
void	env(char **cmd, char **envp);
int		ft_exit(char **cmd);

int		malloc_error(void);
int		road(t_data *data);
int		ft_command(t_data *data);
int		redirection(t_data *data);
void	controller(t_data *data);
int		ft_controller(t_data *data);
void	redirect(int x, int j);
int		ft_strcmp(const char *s1, const char *s2);
void	action(int signum);
int		open_file(t_data *data);
int		ft_pipe(t_data *data, int j, int x);
int		until_equal(char *str);
int		ft_is_numeric(char *str);
int		ft_exit_code(char *str);
int		ft_atollcheck(char *str);

int		parsing(char *rd, t_data **data, char **envp);
char	*parsing_2(char *str);

void	ft_error(char *str);
void	free_tab(char **tmp);

/*###############*/
/*	CHECK ERROR	 */
/*###############*/

int		ft_check_error(t_data *data, char **str);
int		ft_check_error_2(t_data *data, char **str);
int		ft_check_error_21(char **tmp, char **str, t_data *data);
int		ft_check_error_3(t_data *data, char **str, struct stat sb);
int		ft_check_error_3_bis(t_data *data, char **str);

/*#######################*/
/*	 CHECK ERROR UTILS	 */
/*#######################*/

int		check_error_tool(t_data *data, char **str);
int		has_slash(char *str);
char	*getenv_but_better(t_data *data);
int		strcpr(char **tmp, char **str, int i, t_data *data);
char	*getenv_but_better(t_data *data);

/*#######################*/
/*	 FORK FOREVER AFTER	 */
/*#######################*/

void	comewithmeifyouwanttofork(int *pid, int y, t_data *data, char **str);
int		the_fork_outa_names(t_data *data, int x, int j);
void	forkgive_n_forkget(t_data *data, int *pid, int *j, char **str);
int		the_forkiest_fork(t_data *data, int i);
int		straight_outta_forkton(int i, t_data *data, int *j);
void	guns_n_forks(int x, int j, int *pid);
void	forkland(t_data *data, int *pid, int *j);
void	the_fork_before_forks(int *pid, t_data *data, int x, int j);
int		forkland_2_the_forkening(t_data *data, int	*pid, int *j, char *str);
void	extra_cmd(t_data *data, char *str);
t_data	*next_data(t_data *data, int x, int *i);

void	firstcommandclose(t_data *data, int n, int x);
void	lastcommandclose(t_data *data, int n);
void	middlecommandclose(t_data *data, int n);

#endif
