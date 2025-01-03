/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:55:32 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/06/24 14:37:23 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t length)
{
	size_t	index;

	index = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (index < length)
	{
		((char *)dest)[index] = ((const char *)src)[index];
		index++;
	}
	return (dest);
}

/*
 #include <stdio.h>

int main() {
    char str1[] = "Hello";
    char str2[10];  //Enough space to hold "Hello" (including null terminator)

    printf("Original string: %s\n", str1);

    // Copy "Hello" from str1 to str2 using ft_memcpy
    ft_memcpy(str2, str1, sizeof(str1));

    printf("String after ft_memcpy: %s\n", str2);

    return 0;
}
*/
