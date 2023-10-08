/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:49:17 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/08 05:43:19 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/libft.h"
# include <stdio.h>

typedef struct s_map
{
	int	fd;
}	t_map;

typedef struct s_game
{
	int		id;
	t_map	*map;
}	t_game;

int	is_invalid_map_file(int argc, char **argv);
int	is_invalid_arguments(int argc, char **argv);
int	is_invalid_map(int argc, char **argv);

t_game	*load_game(t_game *game, int argc, char **argv);
t_game	*start_game(t_game *game);
t_game	*finish_game(t_game *game);

#endif
