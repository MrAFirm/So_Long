/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:17:47 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/01/17 17:35:53 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int locate_player(t_data *data, int *player_loc)
{
    char    **map_dup;
    int     row;
    int     col;

    map_dup = data->map->map;
    row = -1;
    while (map_dup[row++])
    {
        col = -1;
        while (map_dup[row][col++])
        {
            if (map_dup[row][col] == 'P')
            {
                player_loc[0] = row;
                player_loc[1] = col;
                return (EXIT_SUCCESS);
            }
        }
    }
    return (EXIT_FAILURE);
}
