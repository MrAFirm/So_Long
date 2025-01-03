/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:55:28 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/06/24 14:37:01 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * using unsigned char for typecasting from int to char 
 * using void *ptr and the total amount of 
 * byte size more than the byte size for change, 
 * and increment as the value changes.
 *  And finally return the initial ptr for char *. 
 * Since the ptr is void, it can be anything.
 * */

void	*ft_memset(void *ptr, int value, size_t number)
{
	unsigned char	char_val;
	size_t			index;

	char_val = (unsigned char)value;
	index = 0;
	while (index < number)
	{
		((char *)ptr)[index] = char_val;
		index++;
	}
	return (ptr);
}

/*
*#include <stdio.h>
*int main()
*{
*char str[10] = "Hello";
*printf("Original string: %s\n", str);
* Fill a portion of the string with 'X' (value 88)
*ft_memset(str + 3, 88, 3);  
* Modify starting index and bytes needed
*printf("String after ft_memset: %s\n", str);
*}
*/
