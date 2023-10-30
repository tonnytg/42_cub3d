/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:29:54 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/29 23:08:24 by lbiasuz          ###   ########.fr       */
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

void	draw_line(t_game *game, t_inp a, t_inp b)
{
	t_inp	d;
	t_inp	s;
	int		err;
	int		e2;

	s = (t_inp){.x = (a.x < b.x) - (1 * (a.x >= b.x)),
		.y = (a.y < b.y) - (1 * (a.y >= b.y))
	};
	d = (t_inp){.x = abs(b.x - a.x), .y = abs(b.y - a.y)};
	err = ((((d.x * (d.x > d.y)) + (-d.y * (d.x <= d.y))))) / 2;
	while (a.x != b.x || a.y != b.y)
	{
		mlx_pixel_put(game->mlx, game->window, a.x, a.y, LINE_COLOR);
		e2 = err;
		if (e2 > -d.x)
		{
			err -= d.y;
			a.x += s.x;
		}
		if (e2 < d.y)
		{
			err += d.x;
			a.y += s.y;
		}
	}
}

void	draw_player(t_game *game)
{
	t_inp	pl;
	t_inp	el;

	pl.x = game->player.x * TILE_SIZE;
	pl.y = game->player.y * TILE_SIZE;
	el.x = pl.x + 6 * cos(game->player.angle * (M_PI / 180.0));
	el.y = pl.y + 6 * sin(game->player.angle * (M_PI / 180.0));
	draw_circle(game, pl.x, pl.y, PLAYER_SIZE);
	draw_line(game, pl, el);
}
