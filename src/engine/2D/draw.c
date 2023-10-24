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

void	draw_box(t_game *game, int fov_id, int line_length)
{
	int	x;
	int	y;
	int	corrected_height;
	int	start_y;
	int	end_x;

	x = fov_id * (game->engine->width / FOV);
	if (line_length == 0)
		corrected_height = game->engine->height / 1;
	else
		corrected_height = game->engine->height / line_length;
	start_y = (game->engine->height / 2) - (corrected_height / 2);
	end_x = x + (game->engine->width / FOV);
	while (x < end_x)
	{
		y = start_y;
		while (y < (start_y + corrected_height))
		{
			mlx_pixel_put(game->engine->mlx, game->engine->window, x, y,
				0x000FF);
			y++;
		}
		x++;
	}
}
