/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:35:20 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/17 01:50:08 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	put_image(t_game *game, int *image, int x, int y)
{
	mlx_put_image_to_window(game->engine->mlx,
		game->engine->window,
		image,
		x * TILE_SIZE,
		y * TILE_SIZE);
}
