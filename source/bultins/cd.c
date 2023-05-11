/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:05:30 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/11 17:34:32 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_pwd(char *str, char **envp)
{
	char cwd[256];
	char *tmp;
	int	i;


	i = 0;
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (0);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], str, ft_strlen(str)) == 0)
		{
			tmp = ft_strjoin(str, cwd);
			if (!tmp)
			{
				ft_error("malloc");
				g_exitcode = 1;
				return (-1);
			}
			envp[i] = tmp;
			free(tmp);
		}
		i++;
	}
	// tmp = ft_strjoin(str, cwd);
	// if (!tmp)
	// {
	// 	ft_error("malloc");
	// 	g_exitcode = 1;
	// 	return (-1);
	// }
	// tmptab = ft_split(tmp, ' ');
	// free(tmp);
	// if (!tmptab)
	// {
	// 	ft_error("malloc");
	// 	g_exitcode = 1;
	// 	return (-1);
	// }
	// export(tmptab, envp);
	// free_tab(tmptab);
	// free(tmptab);
	// free(tmp);
	return (1);
}

int	cd(char **cmd, char **envp)
{
	if (change_pwd("export OLDPWD=", envp) == -1)
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
	if (change_pwd("export PWD=", envp) == -1)
		return (-1);
	return (0);
}
