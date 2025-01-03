/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:43:11 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/06/24 14:41:37 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*concatenate;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	concatenate = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!concatenate)
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

/*
#include <stdio.h>

int main (void)
{
	char *s1 = "my favorite animal is";
    char *s2 = " ";
    char *s3 = "the nyancat";
    char *res = ft_strjoin(ft_strjoin(s1, s2), s3);

	printf("answer: %s\n", res);
}
*/