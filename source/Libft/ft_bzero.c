/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:31:33 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/06 19:02:17 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *arr, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)arr;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

/*
#include <string.h>
#include <stdio.h>

int	main()
{
	char str1[10] = "123";
	char str2[10] = "123";

	bzero(str1, 0);
	ft_bzero(str2, 0);
	printf("mine : %s\nYours : %s", str2, str1);

}
*/
