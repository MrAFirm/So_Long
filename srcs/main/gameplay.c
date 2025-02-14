/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:50:42 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/02/14 20:52:15 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*
To check for unique key symbols for the X11 library for definition.
*/
int on_keypress(int keysym, t_data *data)
{
    (void)data;
    ft_printf("Key Pressed: %d\n", keysym);
    return (0);
}

/*
To execute when the game window is closed by the 'X' button,
to ensure all data is freed.
*/
int    on_destroy(void *param)
{
    t_data *data = (t_data *)param;

    mlx_destroy_window(data->mlx_ptr, data->map.win_ptr);
    mlx_destroy_display(data->mlx_ptr);
    exit(EXIT_SUCCESS);
}

void    gameplay(t_data *data)
{
    init_win_key(data);
    sprites(data);
    print_map(data, data->map.full_map);
}

void    init_win_key(t_data *data)
{
    flood_fill(data);
    data->map.win_ptr = mlx_new_window(data->mlx_ptr, 
                data->map.x * SIZE, 
                data->map.y * SIZE, "So_Long");
    mlx_hook(data->map.win_ptr, KeyRelease, 
                KeyReleaseMask, on_keypress, data);
    mlx_hook(data->map.win_ptr, DestroyNotify, 
                StructureNotifyMask, on_destroy, data);
    mlx_hook(data->map.win_ptr, 2, 1L << 0, keybinds, data);
    mlx_loop_hook(data->mlx_ptr, print_map, data);
}
