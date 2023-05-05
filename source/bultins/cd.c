/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:05:30 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/05 19:18:22 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_pwd(char *str, char **envp)
{
	char cwd[256];
	char *tmp;
	char **tmptab;

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return ;
	tmp = ft_strjoin(str, cwd);
	tmptab = ft_split(tmp, ' ');
	export(tmptab, envp);
	free(tmp);
	free(tmptab);
}

void	cd(char **cmd, char **envp)
{
	change_pwd("export OLDPWD=", envp);
	if (!cmd[1] || ft_strcmp(cmd[1], "~") == 0)
	{
		chdir(getenv("HOME"));
	}
	else if (chdir(cmd[1]) == -1)
	{
		ft_printf("cd: %s: %s\n", strerror(errno), cmd[1]);
		return ;
	}
	change_pwd("export PWD=", envp);
}
