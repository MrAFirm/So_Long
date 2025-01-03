/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:24:36 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/06/24 14:34:10 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t size)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				index;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	index = 0;
	while (index < size)
	{
		if (str1[index] != str2[index])
			return (str1[index] - str2[index]);
		index++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int main (void)
{
		char *s1 = "\xff\xaa\xde\x12";
		char *s2 = "\xff\xaa\xde\x12MACOSAAAAA";
		size_t size = 4;
		int i1 = memcmp(s1, s2, size);
		int i2 = ft_memcmp(s1, s2, size);

	printf("memcmp: %d\nft_memcmp: %d\n", i1, i2);
}
*/