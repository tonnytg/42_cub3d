/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:49:17 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/04 04:57:13 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_game
{
	int	id;

}	t_game;

int	load_settings(t_game *game, int argc, char **argv);
int	is_invalid_arguments(int argc, char *argv[]);
int	is_invalid_map(int argc, char *argv[]);

int	start_game(t_game *game);
int	finish_game(t_game *game);

#endif
