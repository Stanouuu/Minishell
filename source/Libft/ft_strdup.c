/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:46:35 by sbarrage          #+#    #+#             */
/*   Updated: 2022/05/09 03:07:20 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	char		*dup;
	size_t		n;

	n = 0;
	dup = malloc(sizeof(char) * (ft_strlen(source) + 1));
	if (!dup)
		return (0);
	while (n < ft_strlen(source))
	{
		dup[n] = source[n];
		n++;
	}
	dup[n] = '\0';
	return (dup);
}
/*
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    const char * original = "The original string.";

    // On duplique la chaîne de caractères initiale.
    char * copy = strdup( original );
    
    // On passe chaque lettre en majuscule.
    char * ptr = copy;
    while( *ptr != '\0' ) {
        *ptr = toupper( *ptr );
        ptr++;
    }

    // On affiche la chaîne finale
    printf( "%s\n", copy );

    // Sans oublier de libérer l'espace mémoire au final.
    free( copy );

    return EXIT_SUCCESS;
}*/
