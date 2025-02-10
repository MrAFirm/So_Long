/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:13:04 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/02/10 16:48:40 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void    gameplay(t_data *data)
{
    init_win_key(data);
    init_sprites(data->sprites, data->sprites->player);
    print_map(data, data->map->full_map);
}

/*
To check for unique key symbols for the X11 library for definition.
*/
int on_keypress(int keysym, t_data *data)
{
    (void)data;
    printf("Pressed Key: %d\\n", keysym);
    return (0);
}

void    init_win_key(t_data *data)
{
    flood_fill(data);
    data->map = mlx_new_window(data->mlx_ptr, 
                data->map->x * SIZE, 
                data->map->y * SIZE, "So_Long");
    mlx_hook(data->win_ptr, KeyRelease, 
                KeyReleaseMask, &on_keypress, &data);
    mlx_hook(data->win_ptr, DestroyNotify, 
                StructureNotifyMask, &on_destroy, &data);
    mlx_hook(data->win_ptr, 2, 1L << 0, &keybinds, &data);
    mlx_hook(data->win_ptr, 17, 0, &esc_press, &data);
}
