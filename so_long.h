/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:16:40 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/12/05 22:16:40 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define DEFAULT_COLOR 0x00000000

# define FALSE 1
# define TRUE 0
# define ARROW_LEFT 110
# define ARROW_RIGHT 120
# define ARROW_DOWN 140
# define ARROW_UP 130
# define IMG_WIDTH 64
# define IMG_HEIGHT 64

# include <stddef.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft/libft.h"

typedef struct	s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct	s_map
{
	char	collectables;
	char	walls;
	char	player;
	char	exit;
}			t_map;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		img_width;
	int		img_height;
	void	*textures[5]; //MLX image pointers (on the stack)
	t_map	*map;
}			t_data;

# endif