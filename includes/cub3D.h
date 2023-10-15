/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:49:17 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/16 00:22:57 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <libft.h>
# include <get_next_line.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <math.h>

# define MAX_LINE_SIZE 1024
# define PIXEL_SIZE 16
# define MAP_SIZE 16
# define PLAYER_SIZE 6
# define BUFFER_SIZE 1024

# define WIDTH 1024
# define HEIGHT 720

# define ESC 65307
# define UP 119
# define DOWN 115 
# define LEFT 97
# define RIGHT 100

# define UP2 65362
# define DOWN2 65364
# define LEFT2 65361
# define RIGHT2 65363

typedef struct s_player_fov
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	color;
}	t_player_fov;

typedef struct s_images
{
	void	*wall;
	void	*player;
	int		width;
	int		height;
}	t_images;

typedef struct s_engine
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	int		screen_width;
	int		screen_height;
}	t_engine;

typedef struct s_player_line
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_player_line;

typedef struct s_player_circle
{
	int	x_center;
	int	y_center;
	int	radius;
	int	color;
	int	x;
	int	y;
	int	p;
}	t_player_circle;

typedef struct s_player
{
	t_player_fov	*fov_line;
	t_player_line	*line;
	t_player_circle	*circle;
	int				x;
	int				y;
	float			angle;
	int				moved;
	int				collected;
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		fd;
	int		lines;
	int		columns;
}	t_map;

typedef struct s_game
{
	t_map		*map;
	t_engine	*engine;
	t_images	*images;
	t_player	*player;
	int			id;	
}	t_game;

/* Read Map */
int		count_columns(char *str, int *columns);
int		open_file(t_game *game, char **argv);
int		is_invalid_map_file(int argc, char **argv);
int		is_invalid_arguments(int argc, char **argv);
int		is_invalid_map(int argc, char **argv);
int		read_map(t_game *game);
int		get_size_map(t_game *game);
int		verify_grid(char **grid);

/* 2D */
void	set_value_to_draw_line(t_player_line *l);
void	draw_fov_lines(t_game *game);

/* Images */
int		load_images(t_game *game);
void	put_image(t_game *game, int *image, int x, int y);

/* Map in MLX */
int		build_map(t_game *game);

/* Player */
void	put_player(t_game *game, int x, int y);
void	draw_line(t_game *game);
void	draw_circle(t_game *game);

/* Core */
t_game	*load_game(t_game *game, char **argv);
t_game	*start_game(t_game *game);
t_game	*finish_game(t_game *game);

/* Events */
int		key_press(int keycode, t_game *game);

/* Clean or Exit */
t_game	*clean_map(t_game *game);
int		clean_struct(t_game *game);
void	exit_game(t_game *game);

/* Utils */
void	print_map_prompt(t_game *game);

#endif
