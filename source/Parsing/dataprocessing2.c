/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataprocessing2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranque <gfranque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:25:06 by gfranque          #+#    #+#             */
/*   Updated: 2023/05/11 22:48:32 by gfranque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "dataprocessing.h"

void	ft_dataclear(t_data *data)
{
	t_data	*temp;

	if (!data)
		return ;
	temp = data;
	while (data != NULL)
	{
		data = data->next;
		if (temp->command != NULL)
			ft_free_strs(temp->command);
		if (temp->files != NULL)
			ft_fileclear(temp->files);
		free (temp);
		temp = data;
	}
}

t_data	*ft_datacreate(char **envp)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->envp = envp;
	data->command = NULL;
	data->files = NULL;
	data->pipe[0] = -1;
	data->pipe[1] = -1;
	return (data);
}

t_data	*ft_dataadd(t_data *data, char **envp)
{
	t_data	*temp;

	temp = data;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = ft_datacreate(envp);
	if (temp->next == NULL)
		return (ft_dataclear(data), NULL);
	return (data);
}

int	ft_checkdata(t_data *data)
{
	char	*newstr;
	t_data	*temp;

	temp = data;
	while (temp != NULL)
	{
		if (temp->command == NULL)
		{
			newstr = ft_strndup("", 0);
			if (!newstr)
				return (0);
			temp->command = ft_commandcreate(temp->command, newstr);
			if (temp->command == NULL)
				return (0);
		}
		temp = temp->next;
	}
	return (1);
}

t_data	*ft_parse(char *str, t_token *begin, t_data *data)
{
	int		i;
	int		res;
	t_token	*temp;

	i = 0;
	res = 1;
	temp = begin;
	if (begin == NULL)
		return (NULL);
	while (temp != NULL)
	{
		if (temp->enu >= 1 && temp->enu <= 4)
			res = ft_rediradd(str, &i, &temp, data);
		else if (temp->enu == pip)
			res = ft_pipeadd(str, &i, &temp, data);
		else if (temp->enu == none)
			res = ft_none(str, &i, &temp);
		else
			res = ft_commandadd(str, &i, &temp, data);
		if (res == 0)
			return (ft_dataclear(data), NULL);
	}
	ft_checkdata(data);
	ft_tokenclear(begin);
	return (data);
}
