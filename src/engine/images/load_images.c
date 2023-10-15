/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:34:55 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/16 00:00:05 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	load_images(t_game *game)
{
	game->images->wall = mlx_xpm_file_to_image(game->engine->mlx,
			"textures/wall.xpm",
			&game->images->width, &game->images->height);
	if (!game->images->wall)
		return (1);
	return (0);
}
