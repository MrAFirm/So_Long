/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putuint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:23:27 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/07/18 21:21:56 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint(unsigned int n)
{
	unsigned long	number;
	int				count;

	number = n;
	count = 0;
	if (number > 9)
	{
		count += ft_putnbr(number / 10);
		count += ft_putchar((number % 10) + '0');
	}
	else
	{
		count += ft_putchar(number + '0');
	}
	return (count);
}
