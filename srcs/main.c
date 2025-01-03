/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:37:11 by lkhye-ya          #+#    #+#             */
/*   Updated: 2024/11/21 15:37:11 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../minilibx_linux/mlx.h"
#include "../minilibx_linux/mlx_int.h"
#include <stdio.h>

int on_destroy(t_data *data)
{
    mlx_destroy_window(data -> mlx_ptr, data -> win_ptr);
    mlx_destroy_display(data -> mlx_ptr);
    free(data -> mlx_ptr);
    exit(EXIT_SUCCESS);
    return (0);
}

int on_keypress(int keysym, t_data *data)
{
    (void)data;
    printf("Pressed Key: %d\\n", keysym);
    return (0);
}

int main(void)
{
    t_data data;

    data.img_width = 64;
    data.img_height = 64;
    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
        return (EXIT_FAILURE);
    data.win_ptr = mlx_new_window(data.mlx_ptr, 1280, 900, "Welcome to my window for So_Long");
    if (data.win_ptr == NULL)
    {
        free(data.win_ptr);
        return (EXIT_FAILURE);
    }
    mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
    mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

    data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, "Assets/Fences.xpm", &data.img_width, &data.img_height);
    if (data.img_ptr == NULL)
        return (EXIT_FAILURE);
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 64, 64);
    mlx_loop(data.mlx_ptr);
    return (0);
}
