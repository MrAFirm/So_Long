/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:28:02 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/06/24 14:27:23 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_ptr;

	if (!lst || !del)
		return ;
	else
	{
		while (*lst)
		{
			lst_ptr = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = lst_ptr;
		}
		lst = NULL;
	}
}
