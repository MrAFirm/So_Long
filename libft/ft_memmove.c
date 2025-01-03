/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:32:05 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/06/13 18:52:00 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t length)
{
	char	*dst;
	char	*s;

	dst = (char *)dest;
	s = (char *)src;
	if (!dest && !src)
		return (0);
	if (dest <= src)
	{
		while (length--)
			*dst++ = *s++;
	}
	else if (dest > src)
	{
		dst += length - 1;
		s += length - 1;
		while (length--)
			*dst-- = *s--;
	}
	return (dest);
}
