/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_conca.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:01:19 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/15 23:15:22 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	conca_export_2(char ***envp, char *str)
{
	int	i;
	int	k;

	k = 0;
	while ((*envp)[k])
	{
		i = until_equal((*envp)[k]);
		if (ft_strncmp(str, (*envp)[k], i) == 0
			&& until_equal((*envp)[k]) == until_equal(str))
		{
			while ((*envp)[k][i] && (*envp)[k][i] != '=')
				i++;
			if (!(*envp)[k][i])
				(*envp)[k] = ft_strjoinandfree((*envp)[k], "=", 0);
			(*envp)[k] = ft_strjoinandfree((*envp)[k], str + i + 1, 0);
			free(str);
			return (1);
		}
		k++;
	}
	if (export_1(&str, envp, 0) == -1)
		return (free(str), -1);
	return (free(str), 1);
}

int	check_conca(char *str, int i)
{
	while (i > 0)
	{
		if (ft_isalpha(str[i]) == 0)
		{
			write(2, "bash: export: ", 14);
			write(2, str, ft_strlen(str));
			write(2, ": not a valid identifier\n", 25);
			return (0);
		}
		i--;
	}
	return (1);
}

int	conca_str(char ***envp, char **cmd, int j, int i)
{
	char	*str;

	str = malloc(sizeof(char) * i);
	i = 0;
	while (cmd[j][i] != '+')
	{
		str[i] = cmd[j][i];
		i++;
	}
	while (cmd[j][i + 1])
	{
		str[i] = cmd[j][1 + i];
		i++;
	}
	str[i] = 0;
	return (conca_export_2(envp, str));
}

int	conca_export(char **cmd, char ***envp, int j)
{
	int	i;

	i = 0;
	if (ft_isalpha(cmd[j][i]) == 0)
		return (0);
	while (cmd[j][i] && cmd[j][i] != '=')
		i++;
	if (!(cmd[j][i - 1] == '+') || !cmd[j][i])
		return (0);
	if (check_conca(cmd[j], i - 2) == 0)
		return (1);
	i = 0;
	while (cmd[j][i])
		i++;
	return (conca_str(envp, cmd, j, i));
}
