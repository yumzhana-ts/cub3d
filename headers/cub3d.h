/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytsyrend <ytsyrend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:46 by ytsyrend          #+#    #+#             */
/*   Updated: 2024/08/19 20:51:58 by ytsyrend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define PI 3.1415926535

# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line.h"
# include "../mlx/mlx.h"
# include "../headers/ft_printf.h"
# include <ApplicationServices/ApplicationServices.h>
# include <Carbon/Carbon.h>

# define TILE_SIZE 43
typedef struct s_data
{
	int		fd;       // File descriptor for the map file
	char	*line;    // Stores each line read from the file
	int		widthmap;
	int		heightmap;
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	int		player_x;
	int		player_y;
	float	player_angle;
	float	delta_x;
	float	delta_y;
}	t_data;

#define DEBUG 0
#define RESET_COLOR "\033[0m"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define WHITE "\033[0;37m"
#define BOLD_BLACK "\033[1;30m"
#define BG_WHITE "\033[0;47m"
#endif

// Additional prototypes
int	checkextension(char *name)
;
int	exit_point(t_data *game)
;
int	fd_error(char *s)
;
int	main(int argc, char **argv) 
;
int	mlx_init_create_window(t_data *game)
;
int	parsing(int argc, char **argv)
;
int	read_map(char **argv, t_data *m)
;
int handle_keypress(int keysym, t_data *game)
;
void	draw_arrow(t_data *game, int color)
;
void	move_player(t_data *game, int dx, int dy)
;
void display_map(t_data *game)
;
void draw_border(t_data *game, int x, int y, int color)
;
void draw_bottom_border(t_data *game, int x, int y, int color)
;
void draw_left_border(t_data *game, int x, int y, int color)
;
void draw_pixel(t_data *game, int x, int y, int color)
;
void draw_right_border(t_data *game, int x, int y, int color)
;
void draw_square(t_data *game, int x, int y, int color)
;
void draw_top_border(t_data *game, int x, int y, int color)
;
void map_debug(t_data *game)
;
void print_map(t_data *game)
;
