/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:53:17 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/02/12 17:16:39 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int is_surrounded(int row, t_data *data, char *line)
{
    size_t  end;

    if (row == 1 || row == data->map.y)
    {
        while (*line && *line == '1')
            line++;
        if (*line == '\0')
            return (TRUE);
        return (FALSE);
    }
    else
    {
        end = ft_strlen(line) - 1;
        if (line[0] == '1' && line[end] == '1')
            return (TRUE);
        return (FALSE);
    }
}

int check_elem_count(t_data *data, int row, char *line)
{
    if (row != 1 && row != data->map.y)
    {
        while (*line)
        {
            if (*line == 'P')
                data->map.player_count++;
            else if (*line == 'E')
                data->map.exit_count++;
            else if (*line == 'C')
                data->map.collectible_count++;
            else if (*line != '0' && *line != '1')
                return (FALSE);
            line++;
        }
    }
    return (TRUE);
}

int valid_count(t_data *data)
{
    if (data->map.player_count != 1 || data->map.exit_count != 1)
        return (FALSE);
    if (data->map.collectible_count < 1)
        return (FALSE);
    return (TRUE);
}

int map_check(t_data *data)
{
    char    **full_map;
    int     row;
    
    full_map = data->map.full_map;
    row = -1;
    while (++row < data->map.y)
    {
        if (ft_strchr(full_map[row], ' ') != NULL ||
            ft_strchr(full_map[row], '\t') != NULL)
                return (FALSE);
        if (is_surrounded(row + 1, data, full_map[row]) == FALSE)
            return (FALSE);
        if (check_elem_count(data, row + 1, full_map[row]) == FALSE)
            return (FALSE);
    }
    return (valid_count(data));
}
