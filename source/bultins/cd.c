/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:05:30 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/15 13:46:57 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	change_pwd(char *str, char **envp)
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
			if (!join)
			{
				g_exitcode = 1;
				return (-1);
			}
			free(envp[i]);
			envp[i] = join;
			return (1);
		}
		i++;
	}
	return (1);
}

int	cd(char **cmd, char **envp)
{
	if (change_pwd("OLDPWD=", envp) == -1)
		return (malloc_error());
	if (!cmd[1])
	{
		chdir(getenv("HOME"));
	}
	else if (chdir(cmd[1]) == -1)
	{
		ft_printf("cd: %s: %s\n", strerror(errno), cmd[1]);
		return (0);
	}
	if (change_pwd("PWD=", envp) == -1)
		return (-1);
	ft_printf("cd : %d\n", *pwd);
	return (0);
}
