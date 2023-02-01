/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:09:11 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/17 17:32:21 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	ft_bzero(str, nmemb * size);
	return (str);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <assert.h>
// #include <stdint.h>

// int main() {
//     // if (ft_calloc(2147483647, 2147483647) == NULL)
//     //     printf("yeas");
//     // else
//     //     printf("nooo");
//     // return 0;

// 	int size = 8539;

// 	void * d1 = ft_calloc(size, sizeof(int));
// 	void * d2 = calloc(size, sizeof(int));

// 	if (d1 == d2)
// 		printf("sucess");
// 	if (!d1)
// 		printf("d1 NULL");
// 	if (!d2)
// 		printf("d2 NULL");
// 	free(d1);
// 	free(d2);
// }
