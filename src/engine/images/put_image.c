/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:35:20 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/14 13:35:21 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	put_image(t_game *game, int *image, int x, int y)
{
	mlx_put_image_to_window(game->engine->mlx,
		game->engine->window,
		image,
		x * MAP_SIZE,
		y * MAP_SIZE);
}
