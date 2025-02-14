/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:51:54 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/02/14 20:32:33 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int main(int argc, char **argv)
{
    t_data  data;

    input_check(&data, argc, argv);
    init_map(&data, argv[1]);
    gameplay(&data);
    mlx_loop(data.mlx_ptr);

    free_map(&data);
    free_sprites(&data);
    free(data.mlx_ptr);
}

void    input_check(t_data *data, int argc, char **argv)
{
    ft_memset(data, 0, sizeof(t_data));
    if (argc != 2)
    {
        ft_printf("Error: Invalid Number of Arguments.\n");
        exit(EXIT_FAILURE);
    }
    data->fd = open(argv[1], O_RDONLY);
    if (data->fd < 0)
    {
        ft_printf("Error: Cannot open file.\n");
        exit(EXIT_FAILURE);
    }
}

/*
To free map data for errors.
*/
void    free_map(t_data *data)
{
    int i;

    i = -1;
    if (data->map.full_map != NULL)
    {
        while (data->map.full_map[++i])
            free(data->map.full_map[i]);
        free(data->map.full_map);
    }
}

/*
To free sprite data for errors.
*/
void    free_sprites(t_data *data)
{
    if (data->sprites.collectibles != NULL)
        free(data->sprites.collectibles);
    if (data->sprites.exit.exit != NULL)
        free(data->sprites.exit.exit);
    if (data->sprites.walls != NULL)
        free(data->sprites.walls);
    if (data->sprites.character_front != NULL)
        free(data->sprites.character_front);
    if (data->sprites.floors != NULL)
        free(data->sprites.floors);
    free(data);
}

/*
To execute when encountering an error.
*/
void    err_and_exit(t_data *data, char *err_msg)
{
    ft_printf("%s\n", err_msg);
    free_map(data);
    free_sprites(data);
    close(data->fd);
    exit(EXIT_FAILURE);
}
