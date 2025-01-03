/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:35:27 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/06/24 14:20:46 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 if index is lesser than total length of string, 
 allow the ptr to point to the target byte size to fill 0.
 */

void	ft_bzero(void *ptr, size_t number)
{
	unsigned char	*target_byte;
	size_t			index;

	target_byte = ptr;
	index = 0;
	while (index < number)
	{
		target_byte[index] = '\0';
		index++;
	}
}
