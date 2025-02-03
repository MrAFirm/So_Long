/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:25:29 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/01/31 11:26:28 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*
To calculate the number of horizontal dimentions of the map, 
and checks if the rows are all in the same length.
*/
int calc_col(char *map, int size_y)
{
    int     row;
    size_t  len;

    row = 0;
    len = ft_strlen(map[0]);
    while (++row < size_y)
    {
        if (ft_strlen(map[row] != len))
            return (EXIT_FAILURE);
    }
    return (len);
}

/*
To only calculate the number of vertical dimentions of the map, no checks.
*/
int calc_row(char *map)
{
    int     fd;
    int     linecount;
    char    *line;

    fd = open("maps/map1.ber", O_RDONLY);
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
    return (linecount);
}
    