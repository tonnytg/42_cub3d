/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:34:55 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/14 13:34:56 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	load_images(t_game *game)
{
	game->images->wall = mlx_xpm_file_to_image(game->engine->mlx,
			"textures/wall.xpm",
			&game->images->width, &game->images->height);
	game->images->collectible = mlx_xpm_file_to_image(game->engine->mlx,
			"textures/collectible.xpm",
			&game->images->width, &game->images->height);
	game->images->exit = mlx_xpm_file_to_image(game->engine->mlx,
			"textures/exit.xpm",
			&game->images->width, &game->images->height);
	game->images->player = mlx_xpm_file_to_image(game->engine->mlx,
			"textures/player.xpm",
			&game->images->width, &game->images->height);
	if (!game->images->wall
		|| !game->images->collectible
		|| !game->images->exit
		|| !game->images->player)
		return (1);
	return (0);
}
