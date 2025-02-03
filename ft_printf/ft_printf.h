/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:58:05 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/07/18 21:07:56 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

size_t			ft_strlen(const char *str);
int				ft_putnbr(int n);
int				ft_putchar(int c);
int				ft_putstr(char *s);
int				ft_putuint(unsigned int n);
int				ft_puthex_upper(unsigned int num, char hex);
int				ft_puthex_lower(unsigned int num, char hex);
int				ft_putptr(void *ptr);
int				ft_printf(const char *format, ...);
#endif