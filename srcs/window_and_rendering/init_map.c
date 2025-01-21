/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:18:39 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/01/21 17:01:24 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int init_map(t_map *map)
{
    map = malloc(sizeof(t_map));
    if (!map)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int read_map()
{
    
}