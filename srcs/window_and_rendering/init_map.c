/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:18:39 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/02/03 22:56:15 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int init_map(t_data *data)
{
    data->map = malloc(sizeof(t_data));
    if (!data->map)
        err_and_exit(data, "Error: Allocation of Memory for Map failed.\n");
    return (EXIT_SUCCESS);
}

int read_map(t_data *data)
{
    //gnl
}