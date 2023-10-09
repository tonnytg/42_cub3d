/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:49:17 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/09 20:04:51 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>

#define MAX_LINE_SIZE 1024
#define PIXEL_SIZE 32
#define BUFFER_SIZE 42

typedef struct s_engine
{
	void	*mlx;
	void	*window;
	int		width;
	int		height;
	int		screen_width;
	int		screen_height;
	int		count_columns;
	int		count_lines;	
}	t_engine;

typedef struct s_map
{
	int	fd;
}	t_map;

typedef struct s_game
{
	t_map		*map;
	t_engine	*engine;
	int			id;	
}	t_game;

/* Read Map */
int	open_file(t_game *game, char **argv);
int	is_invalid_map_file(int argc, char **argv);
int	is_invalid_arguments(int argc, char **argv);
int	is_invalid_map(int argc, char **argv);
int	read_map(t_game *game);

/* Core */
t_game	*load_game(t_game *game, char **argv);
t_game	*start_game(t_game *game);
t_game	*finish_game(t_game *game);

#endif
