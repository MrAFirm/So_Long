/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:52:41 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/02/14 19:40:04 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char    **map_copy(t_data *data)
{
    char    **map_dup;
    char    **map_sample;
    int     row;

    map_dup = malloc(sizeof(char *) * (data->map.y + 1));
    if (!map_dup)
        err_and_exit(data, "Error: Allocation of Memory for Map Duplicate failed.\n");
    map_sample = data->map.full_map;
    row = -1;
    while (map_sample[++row])
        map_dup[row] = ft_strdup(map_sample[row]);
    map_dup[row] = NULL;
    return (map_dup);
}

void    free_map_data(char  ***map_dup, int **player_loc)
{
    int row;

    row = -1;
    while ((*map_dup)[++row])
        free((*map_dup)[row]);
    free(*map_dup);
    free(*player_loc);
}

void    fill(char **map_dup, int row, int col, t_data *data)
{
    int size_y;
    int size_x;
    
    size_y = data->map.y;
    size_x = data->map.x;
    if ((row < 0) || (col < 0) || (row >= size_y) || (col >= size_x))
        return ;
    if (map_dup[row][col] == '1' || map_dup[row][col] == 'F')
        return ;
    if (remaining_coll(map_dup) == 0 && map_dup[row][col] == 'E')
    {
        data->exit.exit_state = TRUE;
        return ;
    }
    else if (remaining_coll(map_dup) != 0 && map_dup[row][col] == 'E')
        return ;
    map_dup[row][col] = 'F';
    fill(map_dup, row + 1, col, data);
    fill(map_dup, row - 1, col, data);
    fill(map_dup, row, col + 1, data);
    fill(map_dup, row, col - 1, data);
}

void    flood_fill(t_data *data)
{
    int     *player_loc;
    char    **map_dup;

    map_dup = map_copy(data);
    player_loc = malloc(sizeof(int) * 2);
    if (!player_loc)
    {
        free_map_data(&map_dup, &player_loc);
        err_and_exit(data, "Allocation of memory for player location failed.\n");
    }
    locate_player(data, player_loc);
    data->exit.exit_state = FALSE;
    if (remaining_coll(map_dup) == 0 && data->exit.exit_state == FALSE)
    {
        free_map_data(&map_dup, &player_loc);
        err_and_exit(data, "Invalid Map design: " 
            "Collectible inaccessible by player.\n");
    }
    free_map_data(&map_dup, &player_loc);
}
