/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:37:30 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/06/24 14:22:09 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	target_bytes;

	if (size != 0 && nmemb > (UINT_MAX / size))
		return (NULL);
	target_bytes = nmemb * size;
	ptr = malloc(target_bytes);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, target_bytes);
	return (ptr);
}
