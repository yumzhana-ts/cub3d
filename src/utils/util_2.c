/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:23:15 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/19 13:52:08 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Prints the map to the standard output
 */
void print_map(t_data *game)
{
    int i;
    
    i = 0;
    while (i < game->heightmap) 
    {
        printf("%s", game->map[i]);
        i++;
    }
    printf("\n");
}

/**
 * @brief Prints debugging information about the map.
 */
void map_debug(t_data *game)
{
    printf("Map width: %d\n", game->widthmap);
    printf("Map height: %d\n", game->heightmap);
    printf("Map:\n");
    print_map(game);
}