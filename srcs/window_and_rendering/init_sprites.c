/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:21:01 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/02/07 15:57:06 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int init_sprites(t_sprites *sprites, t_player *player)
{
    sprites = malloc(sizeof(t_sprites));
    if (!sprites)
        err_and_exit(sprites, "Error: Allocation of Memory for sprites failed.\n");
    player = malloc(sizeof(t_player));
    if (!player)
        err_and_exit(player, "Error: Allocation of Memory for player sprites failed.\n");
    return (EXIT_SUCCESS);
}

int sprites(t_data *data, t_sprites *sprites)
{
    sprites->walls = mlx_xpm_file_to_image(data->mlx_ptr, WALLS, &data->img_width, &data->img_height);
    sprites->floors = mlx_xpm_file_to_image(data->mlx_ptr, FLOORS, &data->img_width, &data->img_height);
    sprites->player->character_front = mlx_xpm_file_to_image(data->mlx_ptr, CHARACTER_FRONT, &data->img_width, &data->img_height);
    sprites->exit->exit = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, &data->img_width, &data->img_height);
    sprites->collectibles = mlx_xpm_file_to_image(data->mlx_ptr, COLLECTIBLES, &data->img_width, &data->img_height);
    if (!sprites)
        err_and_exit(data, "Error: One or More Sprites does NOT exist.\n");
    return (EXIT_SUCCESS);
}
