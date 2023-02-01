/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:53:12 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/05 22:26:28 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c <= 'Z' && c >= 'A')
		return (c + 32);
	return (c);
}
/*
#include <stdio.h>

int main()
{
	printf("%c\n", ft_tolower('A'));
	printf("%c\n", ft_tolower('\n'));
}*/
