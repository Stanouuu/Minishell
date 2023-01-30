/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:25:37 by sbarrage          #+#    #+#             */
/*   Updated: 2023/01/30 16:02:13 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
# include "Libft/libft.h"
# include "Printf/ft_printf.h"
#include <readline/readline.h>
#include <readline/history.h>
// # include "gnl/get_next_line.h"

void	echo(char *rd);
void	pwd(char *rd);
void	cd(char *rd);

char	*parsing_2(char *str);


#endif