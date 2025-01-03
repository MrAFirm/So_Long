/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:10:59 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/06/24 14:33:01 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Error Handling: Maintains the check for a NULL pointer 
in length and index before the loop.
Character Search: The initial loop (while (index < length)) 
searches for the target character c within the specified memory region 
(limited by n). If found, it returns the pointer to the first occurrence.
Null Terminator Check (Conditional):
This section is only executed when searching for the null terminator (c == '\0').
It iterates further from where the initial loop left off (size_t index).
It checks for null terminators (str[index] == '\0') until it 
either encounters a non-null terminator or reaches the end 
of the specified size (index < length).
If a null terminator is found within the specified size, 
it returns the pointer to that location.
No Match: If no match for the character 
(including the null terminator if searching for '\0')
is found within the specified size,
the function returns NULL.
*/

void	*ft_memchr(const void *s, int c, size_t length)
{
	const unsigned char	*str;
	size_t				index;

	str = (const unsigned char *)s;
	index = 0;
	if (!length && !index)
		return (NULL);
	while (index < length)
	{
		if (str[index] == (unsigned char)c)
			return ((void *)(str + index));
		index++;
	}
	if (c == '\0')
	{
		while (index < length && str[index] == '\0')
		{
			if (index < length)
				return ((void *)(str + index));
			index++;
		}
	}
	return (NULL);
}
