#==================================================
# CONSTANT
#==================================================

CC = gcc
FLAG = -Wall -Werror -Wextra -O3
RM = rm -f

#==================================================
# DECLARATION
#==================================================

NAME = so_long
INCLUDE = ./includes/minilibx_linux/libmlx.a ./includes/lib/libft.a
MLX_FLAG = -L./includes/minilibx_linux -lmlx -L/usr/lib/X11 -lXext -lX11 -lm -lz

LIB_DIR = ./includes/lib
MLX_DIR = ./includes/minilibx_linux
# GNL_DIR = ./includes/get_next_line
# FT_PRINTF_DIR = ./includes/ft_printf

#==================================================
# FILES
#==================================================

SRC = $(wildcard ./srcs/*/*.c) 

OBJ = $(SRC:.c=.o)

#===================================================
# BUILD
#===================================================

all : lib $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAG) -o $@ $^ $(INCLUDE) $(MLX_FLAG) 

lib:
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	# make -C $(GNL_DIR)
	# make -C $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make -C $(LIB_DIR) clean
	# make -C $(GNL_DIR) clean
	# make -C $(FT_PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME) 
	make -C $(LIB_DIR) fclean
	# make -C $(GNL_DIR) fclean
	# make -C $(FT_PRINTF_DIR) fclean
	make -C $(MLX_DIR) clean


re: fclean all

.PHONY: all bonus lib clean fclean re