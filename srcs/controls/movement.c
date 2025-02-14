/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:03:54 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/02/14 19:46:41 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void    move_up(t_data *data, int *player_loc, int *movecount)
{
    char    **map_dup;
    int     act_code;
    
    map_dup = data->map.full_map;
    locate_player(data, player_loc);
    act_code = valid_movement(map_dup, (player_loc)[0] - 1, (player_loc)[1]);
    if (act_code == FALSE)
        return ;
    if (act_code == GAME_OVER)
        quit_game(data, act_code);
    (*movecount)++;
    data->exit.exit_state = act_code;
    map_dup[(player_loc)[0] - 1][(player_loc)[1]] = 'P';
    map_dup[(player_loc)[0]][(player_loc)[1]] = '0';
}

void    move_down(t_data *data, int *player_loc, int *movecount)
{
    char    **map_dup;
    int     act_code;
    
    map_dup = data->map.full_map;
    locate_player(data, player_loc);
    act_code = valid_movement(map_dup, (player_loc)[0] + 1, (player_loc)[1]);
    if (act_code == FALSE)
        return ;
    if (act_code == GAME_OVER)
        quit_game(data, act_code);
    (*movecount)++;
    data->exit.exit_state = act_code;
    map_dup[(player_loc)[0] + 1][(player_loc)[1]] = 'P';
    map_dup[(player_loc)[0]][(player_loc)[1]] = '0';
}

void    move_left(t_data *data, int *player_loc, int *movecount)
{
    char    **map_dup;
    int     act_code;
    
    map_dup = data->map.full_map;
    locate_player(data, player_loc);
    act_code = valid_movement(map_dup, (player_loc)[0], (player_loc)[1] - 1);
    if (act_code == FALSE)
        return ;
    if (act_code == GAME_OVER)
        quit_game(data, act_code);
    (*movecount)++;
    data->exit.exit_state = act_code;
    map_dup[(player_loc)[0]][(player_loc)[1] - 1] = 'P';
    map_dup[(player_loc)[0]][(player_loc)[1]] = '0';
}

void    move_right(t_data *data, int *player_loc, int *movecount)
{
    char    **map_dup;
    int     act_code;
    
    map_dup = data->map.full_map;
    locate_player(data, player_loc);
    act_code = valid_movement(map_dup, (player_loc)[0], (player_loc)[1] + 1);
    if (act_code == FALSE)
        return ;
    if (act_code == GAME_OVER)
        quit_game(data, act_code);
    (*movecount)++;
    data->exit.exit_state = act_code;

    map_dup[(player_loc)[0]][(player_loc)[1] + 1] = 'P';
    map_dup[(player_loc)[0]][(player_loc)[1]] = '0';
}
