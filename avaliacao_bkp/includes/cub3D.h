/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:49:17 by antthoma          #+#    #+#             */
/*   Updated: 2023/11/02 18:19:54 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <math.h>

# include <libft.h>
# include <get_next_line.h>
# include <player.h>

# define WALL_HITT 1
# ifndef MINIMAP
#  define MINIMAP 0
# endif

# define TILE_SIZE 8

# define WIDTH 640
# define HEIGHT 480

# define DEFAULT_SKY_COLOR 0xADD8E6
# define DEFAULT_FLOOR_COLOR 0x808080

/* KEY CODES */
# define ESC 65307
# define UP 119
# define DOWN 115 
# define LEFT 97
# define RIGHT 100
# define UP2 65362
# define DOWN2 65364
# define LEFT2 65361
# define RIGHT2 65363

typedef struct s_img
{
	void	*img;
	char	*path;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_img;

typedef struct s_images
{
	void	*wall_2d;
	char	*wall_2d_path;
	t_img	wall_no;
	t_img	wall_so;
	t_img	wall_we;
	t_img	wall_ea;
	int		floor_color;
	int		sky_color;
	int		width;
	int		height;

}	t_images;

typedef struct s_map
{
	char	**grid;
	int		fd;
	int		lines;
	int		columns;
	int		count_custom_wall_no;
	int		count_custom_wall_so;
	int		count_custom_wall_we;
	int		count_custom_wall_ea;
	int		count_custom_color_f;
	int		count_custom_color_c;
	int		count_player;
	int		count_lines_map;
	int		has_error;
}	t_map;

typedef struct s_game
{
	t_map		*map;
	void		*mlx;
	void		*window;
	t_images	*images;
	t_player	player;
	t_img		floor;
	t_img		sky;
}	t_game;

/* Libs */
int		decode_rgb(int r, int g, int b);

/* Read Map */
int		open_file(t_game *game, char **argv);
int		invalid_map_file(int argc, char **argv);
int		read_map(t_game *game);
int		invalid_grid(t_game *game, char **grid);
double	get_player_angle(char *player_position);
int		discover_player_position(t_game *game);
void	free_array(char **array);
int		count_array(char **array);
int		check_config_has_erros(t_game *game);

/* Images and Colors*/
int		load_images(t_game *game);
int		load_default_images(t_game *game);
int		load_custom_images(t_game *game, char *line);
int		load_default_colors(t_game *game);
int		load_custom_color(t_game *game, char *line, char *config);
void	put_image(t_game *game, int *image, int x, int y);
int		is_invalid_color(char *line);

/* Core */
t_game	*load_game(t_game *game, char **argv);
t_game	*start_game(t_game *game);
t_game	*finish_game(t_game *game);

/* Events */
int		key_press(int keycode, t_game *game);

/* Clean or Exit */
void	clean_gnl(t_game *game);
void	destroy_images(t_game *game);
int		clean_struct(t_game *game);
void	exit_game(t_game *game);

/* Render Game */
void	put_player(t_game *game);
int		render_game(t_game *game);
void	init_fov_line(t_fov_line *l);
void	fov_line_distance(t_game *game, t_fov_line *l);
void	draw_fov(t_game *game, int fov_id, int len);
int		draw_background(t_game *game);
void	draw_player(t_game *game);
int		draw_map(t_game *game);

#endif