/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        : +:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:44:12 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/02/14 14:10:58 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void    put_img_to_win(t_data *data, void *img_ptr, int x, int y)
{
    mlx_put_image_to_window(data->mlx_ptr, data->map.win_ptr, 
    img_ptr, y * SIZE, x * SIZE);
}

int print_map(t_data *data, char **full_map)
{
    int     row;
    int     col;
    row = -1;
    while (data->map.full_map[++row])
    {
        col = -1;
        while (data->map.full_map[row][++col])
        {
            if (data->map.full_map[row][col] == '1')
                put_img_to_win(data, data->sprites.walls, row, col);
            else if (data->map.full_map[row][col] == '0')
                put_img_to_win(data, data->sprites.floors, row, col);
            else if (data->map.full_map[row][col] == 'P')
                put_img_to_win(data, data->sprites.character_front, row, col);
            else if (data->map.full_map[row][col] == 'E')
                put_img_to_win(data, data->sprites.exit.exit, row, col);
            else if (data->map.full_map[row][col] == 'C')
                put_img_to_win(data, data->sprites.collectibles, row, col);
            else
                err_and_exit(data, "Error: Unknown Character present in Map File.\n");
        }
    }
    return (EXIT_SUCCESS);
}
