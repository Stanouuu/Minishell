/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:05:30 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/07 22:36:17 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_pwd(char *str, char **envp)
{
	char cwd[256];
	char *tmp;
	char **tmptab;

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (0);
	tmp = ft_strjoin(str, cwd);
	if (!tmp)
	{
		ft_error("malloc");
		g_exitcode = 1;
		return (-1);
	}
	tmptab = ft_split(tmp, ' ');
	free(tmp);
	if (!tmptab)
	{
		ft_error("malloc");
		g_exitcode = 1;
		return (-1);
	}
	export(tmptab, envp);
	return (1);
}

int	cd(char **cmd, char **envp)
{
	if (change_pwd("export OLDPWD=", envp) == -1)
		return (-1);
	if (!cmd[1] || ft_strcmp(cmd[1], "~") == 0)
	{
		chdir(getenv("HOME"));
	}
	else if (chdir(cmd[1]) == -1)
	{
		ft_printf("cd: %s: %s\n", strerror(errno), cmd[1]);
		return (0);
	}
	if (change_pwd("export PWD=", envp) == -1)
		return (-1);
	return (0);
}
