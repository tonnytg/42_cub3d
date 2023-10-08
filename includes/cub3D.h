/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:49:17 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/08 17:37:39 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

#define MAX_LINE_SIZE 1024

typedef struct s_map
{
	int	fd;
}	t_map;

typedef struct s_game
{
	int		id;
	t_map	*map;
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
