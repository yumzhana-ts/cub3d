/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/19 20:57:31 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Draw vector of player 
 * @callgraph
 */
void	draw_arrow(t_data *game, int color)
{
	int ray_length; // Adjust as necessary
	int j;

	ray_length = 12;
	j = 0;
	while(j < ray_length)
	{
		int x = game->player_x + cos(game->player_angle) * j;
		int y = game->player_y + sin(game->player_angle) * j;
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, x + 1, y + 1, color);
		j++;
	}
}

/**
 * @brief Draw pixel
 * @callgraph
 */
void draw_pixel(t_data *game, int x, int y, int color)
{
    mlx_pixel_put(game->mlx_ptr, game->win_ptr, x + 1, y + 1, color);
}


/**
 * @brief Moves player position and orintation
 * @callgraph
 */
void	move_player(t_data *game, int dx, int dy)
{
	int new_x = game->player_x + dx;
	int new_y = game->player_y + dy;

	if (new_x >= 0 && new_x < game->widthmap * TILE_SIZE && new_y >= 0 && new_y < game->heightmap * TILE_SIZE)
	{
		draw_pixel(game, game->player_x, game->player_y, 0x000000);
		draw_arrow(game, 0x000000);

		// Update the player's position
		game->player_x = new_x;
		game->player_y = new_y;

		// Draw the player at the new position
		draw_pixel(game, game->player_x, game->player_y, 0xFF0000);
		draw_arrow(game, 0xFF0000);
		// draw_arrow(game);
	}
}
