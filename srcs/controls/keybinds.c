/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:00:48 by lkhye-ya          #+#    #+#             */
/*   Updated: 2025/02/03 22:50:13 by lkhye-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int keybinds(int keycode, t_data *data, int *player_loc)
{
    static int  movecount = 0;

    player_loc = malloc(sizeof(int) * 2);
    if (!player_loc)
        err_and_exit(data, "Error: Malloc Failed for Player Location (X & Y).\n");
    player_loc[0] = 0;
    player_loc[1] = 0;
    if (keycode == KEY_W)
        move_up(data, &player_loc, &movecount);
    else if (keycode == KEY_D)
        move_right(data, &player_loc, &movecount);
    else if (keycode == KEY_A)
        move_left(data, &player_loc, &movecount);
    else if (keycode == KEY_S)
        move_down(data, &player_loc, &movecount);
    else
        return (EXIT_SUCCESS);
    ft_printf("Steps Taken: %d", movecount);
    return (EXIT_SUCCESS);
}

void    esc_press(int keycode, t_data *data)
{
    if (keycode == KEY_ESC)
        on_destroy(data);
}
