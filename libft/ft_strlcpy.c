/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:41:14 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/06/24 14:44:20 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t length)
{
	size_t	target_byte;

	target_byte = 0;
	if (length != 0)
	{
		while (src[target_byte] != '\0' && target_byte < length - 1)
		{
			dest[target_byte] = src[target_byte];
			target_byte++;
		}
		dest[target_byte] = '\0';
	}
	return (ft_strlen(src));
}

/*
#include <stdio.h>

int main() {
    char str1[] = "Audio";
    char str2[5];  //Outputs Audi, 5th byte contains
    size_t copied_length = ft_strlcpy(str2, str1, sizeof(str2));

    printf("Original string: %s\n", str1);
    printf("Copied string (length: %zu): %s\n", copied_length, str2);

    return 0;
}
*/
