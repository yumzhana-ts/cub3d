/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/19 20:53:22 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int handle_keypress(int keysym, t_data *game)
{
    if (keysym == kVK_Escape) 
    { // ESC key
        mlx_destroy_window(game->mlx_ptr, game->win_ptr);
        exit(0);
    }
    else if (keysym == kVK_ANSI_D) 
    {
        draw_arrow(game, 0x000000);
        game->player_angle += 0.1;
        if (game->player_angle > 2 * PI)
            game->player_angle -= 2 * PI;
        game->delta_x = cos(game->player_angle) * 5;
        game->delta_y = sin(game->player_angle) * 5;
        draw_arrow(game, 0xFF0000);
    }
    else if (keysym == kVK_ANSI_A)
    {
        draw_arrow(game, 0x000000);
        game->player_angle -= 0.1;
        if (game->player_angle < 0)
            game->player_angle += 2*PI;
        game->delta_x = cos(game->player_angle) * 5;
        game->delta_y = sin(game->player_angle) * 5;
        draw_arrow(game, 0xFF0000);
        //move_player(game, game->delta_x, game->delta_y);
    }
    else if (keysym == kVK_ANSI_W) // Up arrow key
        move_player(game, game->delta_x, game->delta_y);
    else if (keysym == kVK_ANSI_S) { // Down arrow key
        move_player(game, -(game->delta_x), -(game->delta_y));
    }
    return 0;
}