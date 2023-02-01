/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:28:39 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/18 18:50:13 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (0);
	res->content = content;
	res->next = NULL;
	return (res);
}
// int	main()
// {
// 	char s[]= "letsgooo";

// 	free(ft_lstnew(s));
// 	return(0);

// }
