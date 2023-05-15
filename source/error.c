/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:18:19 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/15 21:57:01 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(char *str)
{
	ft_printf("%s: %s\n", str, strerror(errno));
}

void	free_tab(char **tmp)
{
	int	i;

	i = 0;
	if (tmp)
		return ;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

int	malloc_error(void)
{
	ft_error("malloc");
	g_exitcode = 1;
	return (-1);
}

void	free_matrix(char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i])
		free(envp[i++]);
	free(envp);
}

void	free_pwd(char **envp)
{
	int			i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PWD=", 4) == 0)
			free(envp[i]);
		else if (ft_strncmp(envp[i], "OLDPWD=", 7) == 0)
			free(envp[i]);
		i++;
	}
}
