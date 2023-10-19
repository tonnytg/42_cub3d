/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:06:54 by lbiasuz           #+#    #+#             */
/*   Updated: 2023/10/19 05:59:53 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void draw_box(t_game *game, int fov_id, int line_length)
{
	int x = fov_id * (game->engine->width / FOV);
	int y = (game->engine->height / 2) - (line_length / 2);

	while (x < fov_id * (game->engine->width / FOV) + (game->engine->width / FOV))
	{
		y = (game->engine->height / 2) - (line_length / 2);
		while (y < line_length)
		{
			mlx_pixel_put(game->engine->mlx, game->engine->window, x, y, 0x000FF);
			y++;
		}
		x++;
	}
}

