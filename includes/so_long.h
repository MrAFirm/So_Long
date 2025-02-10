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

# define WALLS "/mnt/c/Users/Golde/OneDrive/Desktop/Assets/Walls.xpm"
# define FLOORS "/mnt/c/Users/Golde/OneDrive/Desktop/Assets/Grass.xpm"
# define CHARACTER_FRONT "/mnt/c/Users/Golde/OneDrive/Desktop/Assets/Character_front.xpm"
# define EXIT "/mnt/c/Users/Golde/OneDrive/Desktop/Assets/Door.xpm"
# define COLLECTIBLES "/mnt/c/Users/Golde/OneDrive/Desktop/Assets/Egg_item.xpm"

# define FALSE 0
# define TRUE 1
# define EXIT_OPEN 2
# define GAME_OVER 3
# define SIZE 50
# define ARROW_LEFT 110
# define ARROW_RIGHT 120
# define ARROW_DOWN 140
# define ARROW_UP 130
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
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../get_next_line/get_next_line_bonus.h"
# include "../minilibx_linux/mlx.h"
# include "../minilibx_linux/mlx_int.h"
# include "../ft_printf/ft_printf.h"

typedef struct	s_map
{
	char	**full_map;
	int		x;
	int		y;
	int		collectible_count;
	int		player_count;
	int		exit_count;
}			t_map;

typedef struct	s_player
{
	void	*character_front;
	void	*character_back;
	void	*character_left;
	void	*character_right;
}			t_player;

typedef struct	s_exit
{
	void	*exit;
	int		exit_checks;
	int		exit_state;
}			t_exit;

typedef struct	s_sprites
{
	void		*walls;
	void		*floors;
	void		*collectibles;
	t_player	*player;
	t_exit		*exit;
}	t_sprites;

typedef struct	s_data
{
	void		*mlx_ptr; 
	void		*win_ptr;
	int			img_width;
	int			img_height;
	int			s_counter;
	int			collected;
	t_map		*map;
	t_sprites	*sprites;
	t_player	*player_pos;
	t_exit		*exit;
}			t_data;

/* Movement & Controls */
int 		locate_player(t_data *data, int *player_loc);
int 		remaining_coll(char **map_dup);
int 		valid_movement(char **map_dup, int row, int col);
int 		quit_game(t_data *data, int act_code);
void    	move_up(t_data *data, int *player_loc, int *movecount);
void    	move_down(t_data *data, int *player_loc, int *movecount);
void    	move_left(t_data *data, int *player_loc, int *movecount);
void    	move_right(t_data *data, int *player_loc, int *movecount);
int 		keybinds(int keycode, t_data *data, int *player_loc);
int    		on_destroy(void *param);
void    	esc_press(int keycode, t_data *data, int *player_loc);

/* Map Checks */
int 		valid_count(t_map *map_data);
int 		check_elem_count(t_data *data, int row, int size_y, char *line);
int			is_surrounded(int row, int size_y, char *line);
int 		map_check(t_data *data, int size_y);
int 		calc_col(char *map, int size_y);
int 		calc_row(char *map);

/* Flood Fill Alg*/
static char **map_copy(t_data *data);
static char free_map_data(char  ***map_dup, int **player_loc);
void    	fill(char **map_dup, int row, int col, t_data *data);
void    	flood_fill(t_data *data);

/* Window & Rendering */
int 		init_map(t_data *data, char *map);
int 		read_map(t_data *data, int size_y);
int 		init_sprites(t_sprites *sprites, t_player *player);
int 		sprites(t_data *data, t_sprites *sprites);
void		put_img_to_win(t_data *data, void *img_ptr, int x, int y);
int 		print_map(t_data *data, char **map);

/* Main Functions */
int 		on_keypress(int keysym, t_data *data);
void    	gameplay(t_data *data);
void    	init_win_key(t_data *data);
void    	free_map(t_data *data);
void    	free_sprites(t_data *data);
void    	err_and_exit(t_data *data, char *err_msg);
void    	init_mlx(int fd, int argc, char **argv);
int 		main(int argc, char **argv);

# endif