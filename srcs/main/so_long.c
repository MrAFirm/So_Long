/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:12:53 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/01/31 12:12:53 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*
To execute when the game window is closed by the 'X' button,
to ensure all data is freed.
*/
int    on_destroy(void *param)
{
    t_data *data = (t_data *)param;

    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    exit(EXIT_SUCCESS);
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

/*
To free map data for errors.
*/
void    free_map(t_data *data)
{
    if (data->map != NULL)
    {
        int i;

        i = -1;
        if (data->map->full_map != NULL)
        {
            while (data->map->full_map[i++])
                free(data->map->full_map[i]);
        }
        free(data->map);
    }
}

/*
To free sprite data for errors.
*/
void    free_sprites(t_data *data)
{
    if (data->sprites != NULL)
    {
        if (data->sprites->collectibles != NULL)
            free(data->sprites->collectibles);
        if (data->sprites->exit != NULL)
            free(data->sprites->floors);
        if (data->sprites->walls != NULL)
            free(data->sprites->walls);
        if (data->sprites->player != NULL)
        {
            if (data->sprites->player->character_back != NULL)
                free(data->sprites->player->character_back);
            if (data->sprites->player->character_front != NULL)
                free(data->sprites->player->character_front);
            if (data->sprites->player->character_left != NULL)
                free(data->sprites->player->character_left);
            if (data->sprites->player->character_right != NULL)
                free(data->sprites->player->character_right);
        }
    }
}

/*
To execute when encountering an error.
*/
void    err_and_exit(t_data *data, char *err_msg)
{
    ft_printf("%s\n", err_msg);
    free_map(data);
    free_sprites(data);
    exit(EXIT_FAILURE);
}

int main(void)
{
    t_data data;

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
    // print_map(data, data.map);
    mlx_loop(data.mlx_ptr);
    return (0);
}
