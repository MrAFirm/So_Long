/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:51:41 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/02/14 15:44:27 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*
To only calculate the number of vertical dimentions of the map, no checks.
*/
int calc_row(char *map)
{
    int     fd;
    int     linecount;
    char    *line;

    fd = open(map, O_RDONLY);
    if (fd < 0)
        return (EXIT_FAILURE);
    linecount = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        free(line);
        linecount++;
    }
    close(fd);
    return (linecount);
}

/*
To calculate the number of horizontal dimentions of the map, 
and checks if the rows are all in the same length.
*/
int calc_col(t_data *data)
{
    int     row;
    size_t  len;

    row = -1;
    len = ft_strlen(data->map.full_map[0]);
    while (++row < data->map.y)
    {
        if (ft_strlen(data->map.full_map[row]) != len)
        {
            ft_printf("Error: Rows are not the same length.\n");
            exit(EXIT_FAILURE);
        }
    }
    return (len);
}
