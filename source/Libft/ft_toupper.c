/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:00:56 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/06 22:52:49 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c <= 'z' && c >= 'a')
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>

int main()
{
	printf("%c\n", ft_toupper('a'));
	printf("%c\n", ft_toupper('\n'));
}*/
