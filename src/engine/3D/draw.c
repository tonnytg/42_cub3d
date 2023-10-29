/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:06:54 by lbiasuz           #+#    #+#             */
/*   Updated: 2023/10/29 00:35:28 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	*texture_addr(t_game *game, int line, int column, int height)
{
	char	*texture_addr;
	int		x;
	int		y;

	x = (column % game->images->width) * game->images->wall_no.bpp / 8;
	y = line * game->images->height / height * game->images->wall_no.len;
	texture_addr = 0;
	if (game->player.line.wall_side == 'N')
		texture_addr = game->images->wall_no.addr;
	else if (game->player.line.wall_side == 'S')
		texture_addr = game->images->wall_so.addr;
	else if (game->player.line.wall_side == 'E')
		texture_addr = game->images->wall_ea.addr;
	else if (game->player.line.wall_side == 'W')
		texture_addr = game->images->wall_we.addr;
	return (texture_addr + y + x);
}

void	draw_box(t_game *game, int x, int len)
{
	int	y;
	int	corrected_height;
	int	start_y;

	corrected_height = HEIGHT - (len * (len != 0));
	start_y = (HEIGHT / 2) - (corrected_height / 2);
	y = start_y;
	while (y < (start_y + corrected_height))
	{
		mlx_pixel_put(
			game->mlx, game->window,
			x, y,
			*(int *) texture_addr(
				game,
				y - start_y, x,
				corrected_height)
			);
		y++;
	}
}
