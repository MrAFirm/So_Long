/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:48:55 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/02/14 20:09:10 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int sprites(t_data *data)
{
    data->sprites.walls = mlx_xpm_file_to_image(data->mlx_ptr, WALLS, 
                    &data->img_width, &data->img_height);
    data->sprites.floors = mlx_xpm_file_to_image(data->mlx_ptr, FLOORS, 
                    &data->img_width, &data->img_height);
    data->sprites.character_front = mlx_xpm_file_to_image(data->mlx_ptr, CHARACTER_FRONT, 
                    &data->img_width, &data->img_height);
    data->sprites.exit.exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, 
                    &data->img_width, &data->img_height);
    data->sprites.collectibles = mlx_xpm_file_to_image(data->mlx_ptr, COLLECTIBLES, 
                    &data->img_width, &data->img_height);
    return (EXIT_SUCCESS);
}
