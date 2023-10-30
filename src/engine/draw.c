/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:06:54 by lbiasuz           #+#    #+#             */
/*   Updated: 2023/10/30 14:34:51 by lbiasuz          ###   ########.fr       */
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

void	draw_fov(t_game *game, int x, int len)
{
	int	y;
	int	corrected_height;
	int	start_y;

	if (len < 0)
		len = 0;
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
