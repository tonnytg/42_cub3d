/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:06:54 by lbiasuz           #+#    #+#             */
/*   Updated: 2023/10/27 21:47:11 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw_box(t_game *game, int fov_id, int line_length)
{
	int		x;
	int		y;
	int		corrected_height;
	int		start_y;
	int		end_x;
	int		texture_x;
	int		texture_y;
	char	*texture_addr;
	int		texture_pixel;

	texture_addr = 0;
	if (game->player->line[fov_id].wall_side == 'N')
		texture_addr = game->images->wall_no_addr;
	else if (game->player->line[fov_id].wall_side == 'S')
		texture_addr = game->images->wall_so_addr;
	else if (game->player->line[fov_id].wall_side == 'E')
		texture_addr = game->images->wall_ea_addr;
	else if (game->player->line[fov_id].wall_side == 'W')
		texture_addr = game->images->wall_we_addr;
	x = fov_id * (game->engine->width / FOV);
	corrected_height = game->engine->height / line_length;
	if (line_length == 0)
		corrected_height = game->engine->height / 1;
	start_y = (game->engine->height / 2) - (corrected_height / 2);
	end_x = x + (game->engine->width / FOV);
	while (x < end_x)
	{
		y = start_y;
		while (y < (start_y + corrected_height))
		{
			texture_x = (x % game->images->width);
			texture_y = ((y - start_y) * game->images->height) \
					/ corrected_height;
			texture_pixel = *(int *)(texture_addr
					+ (texture_y * game->images->wall_no_line_len)
					+ (texture_x * (game->images->wall_no_bpp / 8)));
			mlx_pixel_put(
				game->engine->mlx, game->engine->window, x, y, texture_pixel);
			y++;
		}
		x++;
	}
}
