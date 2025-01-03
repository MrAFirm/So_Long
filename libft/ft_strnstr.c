/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:24:55 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/06/24 14:46:51 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t length)
{
	const char	*haystack;
	const char	*needle;
	size_t		i;

	haystack = (const char *)big;
	needle = (const char *)little;
	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	if (!length)
		return (0);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && i <= length - ft_strlen(needle))
	{
		if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
		{
			return ((char *)haystack);
		}
		i++;
		haystack++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	    char *s1 = "see FF your FF return FF now FF";
        char *s2 = "FF";
        size_t max = strlen(s1);
        char *i1 = strnstr(s1, s2, max);
        char *i2 = ft_strnstr(s1, s2, max);
		
		printf("expected: %s\nreality: %s\n", i1, i2);
}
*/
