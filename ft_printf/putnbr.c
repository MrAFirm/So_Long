/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:08:25 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/07/18 21:16:56 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intchecks(int n)
{
	int	number;
	int	count;

	number = n;
	count = 0;
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
	}
	if (number == 0)
	{
		write(1, "0", 1);
		count = 1;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	number;
	int	count;

	number = n;
	count = 0;
	if (number == -2147483648 || number == 0)
	{
		count = ft_intchecks(number);
		return (count);
	}
	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
		count++;
	}
	if (number > 9)
	{
		count += ft_putnbr(number / 10);
		count += ft_putchar((number % 10) + '0');
	}
	else
		count += ft_putchar(number + '0');
	return (count);
}
