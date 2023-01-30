/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:27:14 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/11 19:48:59 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;
	int	j;

	i = ft_strlen(s);
	j = 0;
	while (i > j)
	{
		f(j, s);
		j++;
		s++;
	}
}

// void	iter(unsigned int i, char *c)
// {
// 	static int indexArray[11] = {0};

// 	if (i > 10 || indexArray[i] == 1)
// 		write(1, "wrong index\n", 12);
// 	else
// 		indexArray[i] = 1;
// 	if (*c >= 'a' && *c <= 'z')
// 		*c = *c - 32;
// 	else if (*c >= 'A' && *c <= 'Z')
// 		*c = *c + 32;
// }

// int	main()
// {
// 	char str[] = "LoReM iPsUm";
// 	ft_striteri(str, &iter);
// 	printf("%s", str);
// }
