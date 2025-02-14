/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:16:27 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/02/14 20:54:12 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int locate_player(t_data *data, int *player_loc)
{
    char    **map_dup;
    int     row;
    int     col;

    map_dup = data->map.full_map;
    row = -1;
    while (map_dup[++row])
    {
        col = -1;
        while (map_dup[row][++col])
        {
            if (map_dup[row][col] == 'P')
            {
                (player_loc)[0] = row;
                (player_loc)[1] = col;
                return (EXIT_SUCCESS);
            }
        }
    }
    return (EXIT_FAILURE);
}

int remaining_coll(char **map_dup)
{
    int row;
    int col;
    int coll_count;

    coll_count = 0;
    row = -1;
    while (map_dup[++row])
    {
        col = -1;
        while (map_dup[row][++col])
        {
            if (map_dup[row][col] == 'C')
                coll_count++;
        }
    }
    return (coll_count);
}

int valid_movement(char **map_dup, int row, int col)
{
    int remaining_colls;

    remaining_colls = remaining_coll(map_dup);
    if (map_dup[row][col] == '1')
        return (FALSE);
    if (map_dup[row][col] == 'C' && remaining_colls == 1)
        return (EXIT_OPEN);
    if (map_dup[row][col] == 'E' && remaining_colls != 0)
        return (FALSE);
    if (map_dup[row][col] == 'E' && remaining_colls == 0)
        return (GAME_OVER);
    ft_printf("Remaining Collectibles: %d\n", remaining_colls);
    return (TRUE);
}

int quit_game(t_data *data, int act_code)
{
    if (act_code == GAME_OVER)
    {
        ft_printf("You Won!\n");
        ft_printf("Remaining Collectibles: 0\n");
        on_destroy(data);
    }
    return (EXIT_SUCCESS);
}