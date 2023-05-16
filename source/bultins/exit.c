/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:43:09 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/16 14:54:31 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(char **cmd)
{
	if (cmd[1] && ft_is_numeric(cmd[1]) == 0)
	{
		g_exitcode = 2;
		ft_printf("Minishell: %s: numeric argument required\n", cmd[1]);
		return (-1);
	}
	if (cmd[1] && cmd[2])
	{
		g_exitcode = 1;
		ft_printf("bash: exit: too many arguments\n");
		return (0);
	}
	if (cmd[1])
		g_exitcode = ft_exit_code(cmd[1]);
	return (-1);
}

int	ft_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]) == 1)
		i++;
	if (str[i] || ft_atollcheck(str) == 0)
		return (0);
	return (1);
}

int	ft_exit_code(char *str)
{
	int	n;

	n = ft_atoi(str);
	if (n < 0)
	{
		n = n % 256;
		n = n + 256;
	}
	else
		n = n % 256;
	return (n);
}

int	ft_atollcheck(char *str)
{
	double	n;
	int		i;
	int		signe;

	i = 0;
	n = 0;
	signe = 1;
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	if (signe == -1 && (n - 1) > 9223372036854775807)
		return (0);
	if (signe == 1 && n > 9223372036854775807)
		return (0);
	return (1);
}
