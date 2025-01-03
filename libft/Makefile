# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/22 16:55:49 by lkhye-ya          #+#    #+#              #
#    Updated: 2024/06/22 21:55:49 by lkhye-ya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlcpy.c ft_strlen.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_atoi.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OFILES = $(SRCS:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OFILES := $(BONUS:.c=.o)

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
	rm -f $(OFILES) $(BONUS_OFILES)

re: fclean all

bonus: $(OFILES) $(BONUS_OFILES)
	$(AR) $(NAME) $^

$(BONUS_OFILES): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all bonus clean fclean re