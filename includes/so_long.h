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

# define WALLS "Assets/walls.xpm"
# define FLOORS "Assets/floors.xpm"
# define CHARACTER_FRONT "Assets/character_front.xpm"
# define EXIT "Assets/exit.xpm"
# define COLLECTIBLES "Assets/collectible.xpm"

# define FALSE 0
# define TRUE 1
# define EXIT_OPEN 2
# define GAME_OVER 3
# define SIZE 50
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ARROW_UP 65362
# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_A 97
# define KEY_ESC 65307
# define IMG_WIDTH 64
# define IMG_HEIGHT 64

# include <stddef.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include "./lib/libft.h"
# include "./lib/get_next_line/get_next_line.h"
# include "./minilibx_linux/mlx.h"
# include "./lib/ft_printf/ft_printf.h"

typedef struct	s_map
{
	char	**full_map;
	int		x;
	int		y;
	int		collectible_count;
	int		player_count;
	int		exit_count;
	void	*win_ptr;
}			t_map;

typedef struct	s_exit
{
	void	*exit;
	int		exit_state;
}			t_exit;

typedef struct	s_sprites
{
	void		*walls;
	void		*floors;
	void		*collectibles;
	void		*character_front;
	t_exit		exit;
}				t_sprites;

typedef struct	s_data
{
	void		*mlx_ptr;
	int			img_width;
	int			img_height;
	int			s_counter;
	int			collected;
	int			fd;
	t_map		map;
	t_sprites	sprites;
	t_exit		exit;
}				t_data;

/* Main Functions */
void    input_check(t_data *data, int argc, char **argv);
void    err_and_exit(t_data *data, char *err_msg);
void    free_map(t_data *data);
void    free_sprites(t_data *data);
int 	on_keypress(int keysym, t_data *data);
int    	on_destroy(void *param);
void    init_win_key(t_data *data);
void    gameplay(t_data *data);

/* Controls and Movement */
int 	locate_player(t_data *data, int *player_loc);
int 	remaining_coll(char **map_dup);
int 	valid_movement(char **map_dup, int row, int col);
int 	quit_game(t_data *data, int act_code);
void    move_up(t_data *data, int *player_loc, int *movecount);
void    move_down(t_data *data, int *player_loc, int *movecount);
void    move_left(t_data *data, int *player_loc, int *movecount);
void    move_right(t_data *data, int *player_loc, int *movecount);
int 	keybinds(int keycode, t_data *data);

/* Map Checks */
int 	calc_row(char *map);
int 	calc_col(t_data *data);
int 	is_surrounded(int row, t_data *data, char *line);
int 	check_elem_count(t_data *data, int row, char *line);
int 	valid_count(t_data *data);

/* Window and Rendering */
void    read_map(t_data *data);
void    init_map_data(t_data *data);
void    init_map(t_data *data, char *filename);
int 	sprites(t_data *data);
int 	init_sprites(t_data *data);
char    **map_copy(t_data *data);
void    free_map_data(char  ***map_dup, int **player_loc);
void    fill(char **map_dup, int row, int col, t_data *data);
void    flood_fill(t_data *data);
void    put_img_to_win(t_data *data, void *img_ptr, int width, int height);
int 	print_map(t_data *data, char **full_map);

# endif
