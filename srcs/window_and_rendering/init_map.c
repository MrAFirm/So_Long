/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:18:39 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/02/05 15:13:07 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*
To read the .ber file and return the 2D array.
*/
char    **read_map(char *map, int size_y)
{
    int     fd;
    int     row;
    char    *line;
    char    **full_map;
    t_data  *data;
    
    fd = open(map, O_RDONLY);
    if (fd < 0)
        return (NULL);
    row = -1;
    while (++row < size_y)
    {
        line = get_next_line(fd);
        if (!line)
            err_and_exit(data, "GNL error.");
        full_map[row] = ft_strtrim(line, "\n\t\r");
        free(line);
        if (!full_map[row])
            err_and_exit(data, "ft_strtrim error.");
        full_map[size_y] = NULL;
        return (full_map);
    }
}

int init_map(t_data *data, char *map)
{
    data->map = malloc(sizeof(t_data));
    if (!data->map)
        err_and_exit(data, "Error: Allocation of Memory for Map failed.\n");
    return (EXIT_SUCCESS);
}
