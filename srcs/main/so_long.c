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
            if (data->sprites->player->character_front != NULL)
                free(data->sprites->player->character_front);
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

void    init_mlx(int fd, int argc, char **argv)
{
    t_data  *data;
    if (argc != 2)
    {
        ft_printf("Error: Invalid Number of Arguments.\n");
        exit(EXIT_FAILURE);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error: Cannot open file.\n");
        exit(EXIT_FAILURE);
    }
    data = malloc(sizeof(t_data));
    if (!data)
    {
        ft_printf("Error: Memory Allocation Failed for t_data\n");
        exit(EXIT_FAILURE);
    }
    data->map = NULL;
    data->sprites = NULL;
    data->player_pos = NULL;
    data->exit = NULL;
}

int main(int argc, char **argv)
{
    t_data  *data;
    int     fd;

    init_mlx(fd, argc, &argv);
    init_map(data, argv[1]);
    gameplay(data);
    mlx_loop(data->mlx_ptr);
    return (0);
}
