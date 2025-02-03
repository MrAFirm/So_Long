# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 20:00:58 by lkhye-ya          #+#    #+#              #
#    Updated: 2024/07/18 20:24:43 by lkhye-ya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = strlen.c putnbr.c putchar.c putstr.c putuint.c \
puthex.c putptr.c ft_printf.c \

OFILES = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar rcs

all: $(NAME)

$(NAME): $(OFILES)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OFILES)

re: clean all

.PHONY: all clean fclean re