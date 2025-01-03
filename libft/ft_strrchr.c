/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 21:53:17 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/06/24 14:47:39 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
This function returns a pointer to the last occurrence of character in str. 
If the value is not found, the function returns a null pointer, 
as the last_match variable will always update as it encounters the character 
in the string until thestring reaches NULL, then to check the NULL terminator,
the if statement is there to check. 
And if the character we want isn't in the string, 
it'll just return NULL as last_match is initialised to NULL.
*/

char	*ft_strrchr(const char *str, int c)
{
	char	*last_match;

	last_match = NULL;
	while (*str != '\0')
	{
		if ((unsigned char)*str == (unsigned char)c)
			last_match = ((char *)str);
		str++;
	}
	if (*str == c)
		last_match = ((char *)str);
	return (last_match);
}
