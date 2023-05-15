/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:58:17 by sbarrage          #+#    #+#             */
/*   Updated: 2023/05/15 16:53:06 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printf_export(int *i, int j, char **envp)
{
	int	k;

	while (j > 0)
	{
		k = 0;
		j--;
		ft_printf("declare -x ");
		while (envp[i[j]][k] && envp[i[j]][k] != '=')
			write(1, &envp[i[j]][k++], 1);
		if (envp[i[j]][k])
		{
			write(1, &envp[i[j]][k++], 1);
			ft_printf("\"%s\"", envp[i[j]] + k);
		}
		write(1, "\n", 1);
	}
}

int	ft_lowest(char **envp)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	j = 0;
	while (envp[i])
	{
		l = 0;
		while (envp[i][l] == envp[j][l] && i != j)
			l++;
		if (envp[i][l] < envp[j][l])
		{
			j = i;
		}
		i++;
	}
	return (j);
}

int	ft_not_in_tab(int *i, int j, int k)
{
	while (j > -1)
	{
		if (i[j] == k)
			return (0);
		j--;
	}
	return (1);
}

void	envp_prt_sort_2(char **envp, int *i, int j, int k)
{
	int	l;

	l = 0;
	while (envp[k][l] == envp[i[j]][l] && k != i[j])
		l++;
	if (envp[k][l] > envp[i[j]][l] && ft_not_in_tab(i, j, k))
		i[j] = k;
}

int	envp_prt_sort(char **envp)
{
	int	*i;
	int	k;
	int	j;

	k = 0;
	while (envp[k])
		k++;
	i = malloc(sizeof(int) * k);
	if (!i)
	{
		g_exitcode = 1;
		ft_error("malloc");
		return (-1);
	}
	j = 0;
	while (envp[j])
	{
		i[j] = ft_lowest(envp);
		k = 0;
		while (envp[k])
			envp_prt_sort_2(envp, i, j, k++);
		j++;
	}
	return (printf_export(i, j, envp), free(i), 1);
}
