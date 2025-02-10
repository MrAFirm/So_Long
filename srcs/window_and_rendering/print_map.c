/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:23:44 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/02/07 15:09:22 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void    put_img_to_win(t_data *data, void *img_ptr, int x, int y)
{
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
    data->sprites, IMG_WIDTH * 50, IMG_HEIGHT * 50);
}

int print_map(t_data *data, char **full_map)
{
    int     row;
    int     col;
    
    row = -1;
    while (full_map[++row])
    {
        col = -1;
        while (full_map[row][++col])
        {
            if (full_map[row][col] == '1')
                put_img_to_win(data, data->sprites->walls, row, col);
            else if (full_map[row][col] == '0')
                put_img_to_win(data, data->sprites->floors, row, col);
            else if (full_map[row][col] == 'P')
                put_img_to_win(data, data->sprites->player->character_front, row, col);
            else if (full_map[row][col] == 'E')
                put_img_to_win(data, data->sprites->exit->exit, row, col);
            else
                err_and_exit(data, "Error: Unknown Character present in Map File.\n");
        }
    }
    return (EXIT_SUCCESS);
}
