/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:06:54 by lbiasuz           #+#    #+#             */
/*   Updated: 2023/10/28 11:46:24 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw_box(t_game *game, int fov_id, int len)
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
		texture_addr = game->images->wall_no.addr;
	else if (game->player->line[fov_id].wall_side == 'S')
		texture_addr = game->images->wall_so.addr;
	else if (game->player->line[fov_id].wall_side == 'E')
		texture_addr = game->images->wall_ea.addr;
	else if (game->player->line[fov_id].wall_side == 'W')
		texture_addr = game->images->wall_we.addr;
	x = fov_id * (WIDTH / FOV);
	corrected_height = HEIGHT / len;
	if (len == 0)
		corrected_height = HEIGHT / 1;
	start_y = (HEIGHT / 2) - (corrected_height / 2);
	end_x = x + (WIDTH / FOV);
	while (x < end_x)
	{
		y = start_y;
		while (y < (start_y + corrected_height))
		{
			texture_x = (x % game->images->width);
			texture_y = ((y - start_y) * game->images->height) \
					/ corrected_height;
			texture_pixel = *(int *)(texture_addr
					+ (texture_y * game->images->wall_no.len)
					+ (texture_x * (game->images->wall_no.bpp / 8)));
			mlx_pixel_put(
				game->mlx, game->window, x, y, texture_pixel);
			y++;
		}
		x++;
	}
}
