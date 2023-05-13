/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:05:30 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/13 12:51:30 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_pwd(char *str, char **envp, int pwd)
{
	char		cwd[256];
	char		*join;
	int			i;

	i = 0;
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (0);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], str, ft_strlen(str)) == 0)
		{
			join = ft_strjoin(str, cwd);
			if (!envp[i])
			{
				ft_error("malloc");
				g_exitcode = 1;
				return (-1);
			}
			if (pwd > 0)
				free(envp[i]);
			envp[i] = join;
			return (1);
		}
		i++;
	}
	return (1);
}

int	cd(char **cmd, char **envp, int *pwd)
{
	if (change_pwd("OLDPWD=", envp, *pwd) == -1)
		return (-1);
	if (!cmd[1])
	{
		chdir(getenv("HOME"));
	}
	else if (chdir(cmd[1]) == -1)
	{
		ft_printf("cd: %s: %s\n", strerror(errno), cmd[1]);
		return (0);
	}
	if (change_pwd("PWD=", envp, *pwd) == -1)
		return (-1);
	(*pwd)++;
	ft_printf("cd : %d\n", *pwd);
	return (0);
}
