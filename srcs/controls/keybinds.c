/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:06:08 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/02/14 20:58:58 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int keybinds(int keycode, t_data *data)
{
    static int  movecount = 0;
    int         player_loc[2];
    
    player_loc[0] = 0;
    player_loc[1] = 0;
    if (keycode == KEY_W || keycode == ARROW_UP)
        move_up(data, player_loc, &movecount);
    else if (keycode == KEY_D || keycode == ARROW_RIGHT)
        move_right(data,player_loc, &movecount);
    else if (keycode == KEY_A || keycode == ARROW_LEFT)
        move_left(data, player_loc, &movecount);
    else if (keycode == KEY_S || keycode == ARROW_DOWN)
        move_down(data, player_loc, &movecount);
    else
        return (EXIT_FAILURE);
    ft_printf("Steps Taken: %d\n", movecount);
    return (EXIT_SUCCESS);
}
