/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:49:17 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/22 00:23:09 by antthoma         ###   ########.fr       */
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

# define TILE_SIZE 8
# define TILE_DP 6

# define WIDTH 1024
# define HEIGHT 720

# define DEFAULT_SKY_COLOR 0xADD8E6
# define DEFAULT_FLOOR_COLOR 0x808080

# define ESC 65307
# define UP 119
# define DOWN 115 
# define LEFT 97
# define RIGHT 100

# define UP2 65362
# define DOWN2 65364
# define LEFT2 65361
# define RIGHT2 65363

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_images
{
	void	*wall_2d;
	char	*wall_2d_path;
	void	*wall_no;
	char	*wall_no_path;
    char    *wall_no_addr;  // Novo
    int     wall_no_bpp;    // Novo
    int     wall_no_line_len; // Novo
    int     wall_no_endian;   // Novo	
	void	*wall_so;
	char	*wall_so_path;
    char    *wall_so_addr;  // Novo
    int     wall_so_bpp;    // Novo
    int     wall_so_line_len; // Novo
    int     wall_so_endian;   // Novo	
	void	*wall_we;
	char	*wall_we_path;
    char    *wall_we_addr;  // Novo
    int     wall_we_bpp;    // Novo
    int     wall_we_line_len; // Novo
    int     wall_we_endian;   // Novo	
	void	*wall_ea;
	char	*wall_ea_path;
    char    *wall_ea_addr;  // Novo
    int     wall_ea_bpp;    // Novo
    int     wall_ea_line_len; // Novo
    int     wall_ea_endian;   // Novo	
	void	*player;
	int		floor_color;
	int		sky_color;
	int		width;
	int		height;
}	t_images;

typedef struct s_engine
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
}	t_engine;

typedef struct s_game_background
{
	int		x;
	int		y;
	int		bottom_half_height;
	int		top_half_height;
	t_data	floor;
	t_data	sky;
}	t_game_background;

typedef struct s_map
{
	char				**grid;
	int					fd;
	int					lines;
	int					columns;
	t_game_background	*background;
}	t_map;

typedef struct s_game
{
	t_map		*map;
	t_engine	*engine;
	t_images	*images;
	t_player	*player;
	int			i;
}	t_game;

/* Libs */
int		decode_rgb(int r, int g, int b);

/* Read Map */
int		count_columns(char *str, int *columns);
int		open_file(t_game *game, char **argv);
int		is_invalid_map_file(int argc, char **argv);
int		is_invalid_arguments(int argc, char **argv);
int		is_invalid_map(int argc, char **argv);
int		read_map(t_game *game);
int		verify_grid(char **grid);
double	get_player_angle(char *player_position);
int		discover_player_position(t_game *game);

/* 2D */
void	set_value_to_draw_line(t_fov_line *l);

/* Images and Colors*/
int		load_images(t_game *game);
int		load_default_images(t_game *game);
int		load_custom_images(t_game *game, char *line, char *config);
int		load_default_colors(t_game *game);
int		load_custom_color(t_game *game, char *line, char *config);
void	put_image(t_game *game, int *image, int x, int y);

/* Map in MLX */
int		build_map(t_game *game);

/* Player */
void	put_player(t_game *game);
void	calc_line_fov(t_game *game);

/* Core */
t_game	*load_game(t_game *game, char **argv);
t_game	*start_game(t_game *game);
t_game	*finish_game(t_game *game);

/* Events */
int		key_press(int keycode, t_game *game);

/* Clean or Exit */
void	destroy_images(t_game *game);
int		clean_struct(t_game *game);
void	exit_game(t_game *game);

/* Render Game */
int		render_game(t_game *game);

void	calc_fov_line_distance(t_game *game, int fov_id);
void	draw_box(t_game *game, int fov_id, int line_length);
int		draw_background(t_game *game);

#endif