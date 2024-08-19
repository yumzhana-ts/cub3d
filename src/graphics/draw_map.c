/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/19 20:58:55 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Prints square by tile size with mlx pixel put
 * @callgraph
 */
void draw_square(t_data *game, int x, int y, int color)
{
    int i;
	int j;

	i = 0;
    while (i < TILE_SIZE)
    {
		j = 0;
        while (j < TILE_SIZE)
        {
            mlx_pixel_put(game->mlx_ptr, game->win_ptr, x + i, y + j, color);
			j++;
        }
		i++;
    }
}

// void	draw_player(t_data *game)
// {
// 	mlx_pixel_put(game->mlx_ptr, game->win_ptr, x + i, y + j, color);
// }

/**
 * @brief Prints squares, borders and player of the map
 * @callgraph
 */
void display_map(t_data *game)
{
	int x;
	int y;
	int i;
	int j;

	y = 0;
	x = 0;
	i = 0;
	while(i < game->heightmap)
	{
		j = 0;
		while(j < game->widthmap)
		{
			x = j * TILE_SIZE;
			y = i * TILE_SIZE;
			if (game->map[i][j] == '1')
			{
				draw_square(game, x, y, 0xFFFFFF); // White for '1'
			}
			else if (game->map[i][j] == 'P')
			{
				// game->player_x = 20;
				// game->player_y = 20;
				// mlx_pixel_put(game->mlx_ptr, game->win_ptr, (i * 40) + 20, (j * 40) + 20, 0xFFFFFF); // Red for the player
				game->player_x = x + TILE_SIZE / 2;
				game->player_y = y + TILE_SIZE / 2;
		
				// mlx_pixel_put(game->mlx_ptr, game->win_ptr, game->player_x, game->player_y, 0xFF0000); // Red for the player
				draw_arrow(game, 0xFF0000);
			}
			else
			{
				draw_square(game, x, y, 0x000000); // Black for '0' or other characters
			}
			draw_border(game, x, y, 0x00FFFF);
			j++;
		}
		i++;
	}
}