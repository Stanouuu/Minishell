/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:14:44 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/05 22:21:47 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	return (1);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	int c = 128;
	printf("%i - %i", ft_isascii(c), isascii(c));
}*/
