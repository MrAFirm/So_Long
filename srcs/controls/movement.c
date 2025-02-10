/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:03:54 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/02/07 14:54:34 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void    move_up(t_data *data, int *player_loc, int *movecount)
{
    char    **map_dup;
    int     act_code;
    
    map_dup = data->map->full_map;
    act_code = valid_movement(map_dup, player_loc[0] - 1, player_loc[1]);
    if (act_code == FALSE)
        return ;
    if (act_code == GAME_OVER)
        quit_game(data, act_code);
    movecount++;
    map_dup[(player_loc)[0] - 1][(player_loc)[1]] = 'P';
    map_dup[(player_loc)[0]][(player_loc)[1]] = '0';
}

void    move_down(t_data *data, int *player_loc, int *movecount)
{
    char    **map_dup;
    int     act_code;
    
    map_dup = data->map->full_map;
    act_code = valid_movement(map_dup, player_loc[0] + 1, player_loc[1]);
    if (act_code == FALSE)
        return ;
    if (act_code == GAME_OVER)
        quit_game(data, act_code);
    map_dup = data->map->full_map;
    movecount++;
    map_dup[(player_loc)[0] + 1][(player_loc)[1]] = 'P';
    map_dup[(player_loc)[0]][(player_loc)[1]] = '0';
}

void    move_left(t_data *data, int *player_loc, int *movecount)
{
    char    **map_dup;
    int     act_code;
    
    map_dup = data->map->full_map;
    act_code = valid_movement(map_dup, player_loc[0], player_loc[1] - 1);
    if (act_code == FALSE)
        return ;
    if (act_code == GAME_OVER)
        quit_game(data, act_code);
    map_dup = data->map->full_map;
    movecount++;
    map_dup[(player_loc)[0]][(player_loc)[1] - 1] = 'P';
    map_dup[(player_loc)[0]][(player_loc)[1]] = '0';
}

void    move_right(t_data *data, int *player_loc, int *movecount)
{
    char    **map_dup;
    int     act_code;
    
    map_dup = data->map->full_map;
    act_code = valid_movement(map_dup, player_loc[0], player_loc[1] + 1);
    if (act_code == FALSE)
        return ;
    if (act_code == GAME_OVER)
        quit_game(data, act_code);
    map_dup = data->map->full_map;
    movecount++;
    map_dup[(player_loc)[0]][(player_loc)[1] + 1] = 'P';
    map_dup[(player_loc)[0]][(player_loc)[1]] = '0';
}
