/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:50:51 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/08/22 13:25:44 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*concatenate;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	concatenate = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!concatenate || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		concatenate[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		concatenate[i] = s2[j];
		i++;
		j++;
	}
	concatenate[i] = '\0';
	return (concatenate);
}

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

char	*ft_strchr(const char *str, int c)
{
	const unsigned char	*ptr;
	unsigned char		chck;

	if (str == NULL)
		return (NULL);
	ptr = (const unsigned char *)str;
	chck = (unsigned char)c;
	while (*ptr != '\0')
	{
		if (*ptr == chck)
			return ((char *)ptr);
		ptr++;
	}
	if (chck == '\0')
		return ((char *)ptr);
	return (NULL);
}
