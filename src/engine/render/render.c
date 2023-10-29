/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:29:54 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/29 00:16:40 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw_circle(t_game *game, int x, int y, int r)
{
	int	i;
	int	j;

	i = x - r;
	while (i < x + r)
	{
		j = y - r;
		while (j < y + r)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) < r * r)
				mlx_pixel_put(
					game->mlx, game->window, i, j, CIRCLE_COLOR);
			j++;
		}
		i++;
	}
}

void	draw_line(t_game *game, int x0, int y0, int x1, int y1)
{
	int	dx = abs(x1 - x0);
	int	dy = abs(y1 - y0);
	int	sx = x0 < x1 ? 1 : - 1;
	int	sy = y0 < y1 ? 1 : - 1;
	int	err = (dx > dy ? dx : - dy) / 2;
	int	e2;

	while (x0 != x1 || y0 != y1)
	{
		mlx_pixel_put(game->mlx, game->window, x0, y0, LINE_COLOR);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	draw_player(t_game *game)
{
	int	plx;
	int	ply;

	plx = game->player.x * TILE_SIZE;
	ply = game->player.y * TILE_SIZE;
	draw_circle(game, plx, ply, PLAYER_SIZE);
	draw_line(
		game, plx, ply,
		plx + 6 * cos(game->player.angle * (M_PI / 180.0)),
		ply + 6 * sin(game->player.angle * (M_PI / 180.0)));
}