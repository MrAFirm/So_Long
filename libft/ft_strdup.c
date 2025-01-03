/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:05:36 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/06/24 14:40:39 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
We use size_t for the string length to avoid potential integer overflow issues.
We allocate memory for len + 1 bytes 
to accommodate the string and the null terminator.
The loop copies each character from s to dst and increments both pointers.
After the loop, we explicitly add the null terminator 
to the end of the copied string.
Finally, we return the dst pointer which points 
to the beginning of the duplicated string.
*/

char	*ft_strdup(const char *src)
{
	size_t	length;
	size_t	index;
	char	*dest;

	length = ft_strlen(src);
	index = 0;
	dest = (char *)malloc(sizeof(*src) * length + 1);
	if (!dest)
		return (NULL);
	while (index < length)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
