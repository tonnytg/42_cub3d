/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:49:17 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/10 18:00:47 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <libft.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

# define MAX_LINE_SIZE 1024
# define PIXEL_SIZE 32
# define BUFFER_SIZE 42

# define WIDTH 720
# define HEIGHT 480

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

typedef struct s_engine
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	int		screen_width;
	int		screen_height;
}	t_engine;

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
	int			id;	
}	t_game;

/* Read Map */
int		open_file(t_game *game, char **argv);
int		is_invalid_map_file(int argc, char **argv);
int		is_invalid_arguments(int argc, char **argv);
int		is_invalid_map(int argc, char **argv);
int		read_map(t_game *game);
int		get_size_map(t_game *game);
t_game	*create_map(t_game *game);

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

#endif
