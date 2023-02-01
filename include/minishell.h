/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:25:37 by sbarrage          #+#    #+#             */
/*   Updated: 2023/02/01 18:49:31 by gfranque         ###   ########.fr       */
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

void	echo(char *rd);
void	pwd(char *rd);
void	cd(char *rd);

char	*parsing_2(char *str);

#endif
