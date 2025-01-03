/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:52:41 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/06/24 14:44:01 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	remaining;
	size_t	src_len;
	size_t	total_len;

	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	dst_len = ft_strlen(dest);
	remaining = size - dst_len - 1;
	total_len = dst_len + src_len;
	if (size <= dst_len)
		return (src_len + size);
	i = 0;
	while (src[i] != '\0' && i < remaining)
	{
		dest[dst_len + i] = src[i];
		i++;
	}
	dest[dst_len + i] = '\0';
	return (total_len);
}
