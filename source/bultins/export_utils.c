/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:58:17 by sbarrage          #+#    #+#             */
/*   Updated: 2023/02/16 16:47:33 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			j = i;
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

void	envp_prt_sort(char **envp)
{
	int	*i;
	int	k;
	int	j;

	k = 0;
	while (envp[k])
		k++;
	i = malloc(sizeof(int) * k);
	if (!i)
		ft_error("malloc");
	j = 0;
	while (envp[j])
	{
		i[j] = ft_lowest(envp);
		k = 0;
		while (envp[k])
			envp_prt_sort_2(envp, i, j, k++);
		j++;
	}
	while (j > 0)
		ft_printf("%s\n", envp[i[--j]]);
}
