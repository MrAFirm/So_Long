/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:23:11 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/06/24 14:27:54 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;
	int	j;

	i = ft_lstsize(lst) - 1;
	j = 0;
	if (lst)
	{
		while (j < i)
		{
			lst = lst->next;
			j++;
		}
	}
	return (lst);
}
