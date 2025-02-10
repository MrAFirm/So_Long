/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:15:53 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/02/05 16:43:55 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*
To ensure the valid count for player, exit and collectibles.
*/
int valid_count(t_map *map_data)
{
    if (map_data->player_count != 1 || map_data->exit_count != 1)
        return (FALSE);
    if (map_data->collectible_count < 1)
        return (FALSE);
    return (TRUE);
}


int check_elem_count(t_data *data, int row, int size_y, char *line)
{
    if (row != 1 && row != size_y)
    {
        while (*line)
        {
            if (*line == 'P')
                data->map->player_count++;
            else if (*line == 'E')
                data->map->exit_count++;
            else if (*line == 'C')
                data->map->collectible_count++;
            else if (*line != '0' && *line != '1')
                return (FALSE);
            line++;
        }
    }
    return (TRUE);
}

int is_surrounded(int row, int size_y, char *line)
{
    size_t  end;

    if (row == 1 || row == size_y)
    {
        while (*line && *line == '1')
            line++;
        if (*line == '\0')
            return (TRUE);
        return (FALSE);
    }
    else
    {
        end = ft_strlen(line - 1);
        if (line[0] == '1' & line[end] == '1')
            return (TRUE);
        return (FALSE);
    }
}

int map_check(t_data *data, int size_y)
{
    char    **full_map;
    int     row;
    
    full_map = data->map->full_map;
    row = -1;
    while (++row < size_y)
    {
        if (ft_strchr(full_map[row], " ") != NULL ||
            ft_strchr(full_map[row], "\t") != NULL)
                return (FALSE);
        if (is_surrounded(row + 1, size_y, full_map[row]) == FALSE)
            return (FALSE);
        if (check_elem_count(data, row + 1, size_y, full_map[row]) == FALSE)
            return (FALSE);
    }
    return (valid_count(data->map));
}
