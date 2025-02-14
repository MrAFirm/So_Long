/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:51:27 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/02/14 20:35:15 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int map_check(t_data *data);

void    init_map(t_data *data, char *filename)
{
    data->mlx_ptr = mlx_init();
    if (!data->mlx_ptr)
        err_and_exit(data, "Failed to initialise map.\n");
    data->map.y = calc_row(filename);
    if (data->map.y <= 0)
        err_and_exit(data, "No map to be initalised.\n");
    data->map.full_map = malloc(sizeof(char *) * (data->map.y + 1));
    if (!data->map.full_map)
        err_and_exit(data, "Malloc failed for map.");
    init_map_data(data);
    if (map_check(data) == FALSE)
        err_and_exit(data, "Map is invalid.\n");
}

void    init_map_data(t_data *data)
{
    read_map(data);
    data->map.x = calc_col(data);
    if (!data->map.x)
        err_and_exit(data, "Error: Map cannot be loaded.\n");
    data->map.player_count = 0;
    data->map.collectible_count = 0;
    data->map.exit_count = 0;
}

/*
To read the .ber file and return the 2D array.
*/
void    read_map(t_data *data)
{
    int     row;
    char    *line;
    
    row = -1;
    while (++row < data->map.y)
    {
        line = get_next_line(data->fd);
        if (!line)
            err_and_exit(data, "GNL error.");
        data->map.full_map[row] = ft_strtrim(line, "\n\t\r");
        free(line);
        if (!data->map.full_map[row])
            err_and_exit(data, "ft_strtrim error.");
    }
    data->map.full_map[row] = NULL;
}
