/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:49:20 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/19 16:06:17 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*jim;

	if (lst)
	{
		if (lst[0])
		{
			jim = ft_lstlast(lst[0]);
			jim->next = new;
		}
		else
			lst[0] = new;
	}
}
