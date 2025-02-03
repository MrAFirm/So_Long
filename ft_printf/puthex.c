/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:44:41 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/07/15 23:15:38 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_upper(unsigned int num, char hex)
{
	char			*hex_chars_upper;
	unsigned long	count;
	unsigned char	format;

	format = hex;
	count = 0;
	hex_chars_upper = "0123456789ABCDEF";
	if (format == 'X')
	{
		if (num >= 16)
		{
			count += ft_puthex_upper((num / 16), hex);
			ft_putchar(hex_chars_upper[num % 16]);
			count++;
		}
		else
		{
			ft_putchar(hex_chars_upper[num % 16]);
			count++;
		}
	}
	return (count);
}

int	ft_puthex_lower(unsigned int num, char hex)
{
	char			*hex_chars_lower;
	unsigned long	count;
	unsigned char	format;

	format = hex;
	count = 0;
	hex_chars_lower = "0123456789abcdef";
	if (format == 'x')
	{
		if (num >= 16)
		{
			count += ft_puthex_lower((num / 16), hex);
			ft_putchar(hex_chars_lower[num % 16]);
			count++;
		}
		else
		{
			ft_putchar(hex_chars_lower[num % 16]);
			count++;
		}
	}
	return (count);
}

/*
#include <stdio.h>
int main()
{
	int hi = 12;
	printf("hexdecimal: %d\n", ft_puthex_lower(hi, 'x'));
}
*/