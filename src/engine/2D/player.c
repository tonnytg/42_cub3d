/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:35:12 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/14 14:20:42 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw_circle(t_game *game, int x_center, int y_center, int radius)
{
	t_player_circle	*c;

	c = game->player->circle;
	c->x = radius;
	c->y = 0;
	c->p = 1 - radius;
	while (c->x >= c->y)
	{
		mlx_pixel_put(game->engine->mlx, game->engine->window,
			x_center + c->x, y_center + c->y, c->color);
		mlx_pixel_put(game->engine->mlx, game->engine->window,
			x_center - c->x, y_center + c->y, c->color);
		mlx_pixel_put(game->engine->mlx, game->engine->window,
			x_center + c->x, y_center - c->y, c->color);
		mlx_pixel_put(game->engine->mlx, game->engine->window,
			x_center - c->x, y_center - c->y, c->color);
		mlx_pixel_put(game->engine->mlx, game->engine->window,
			x_center + c->y, y_center + c->x, c->color);
		mlx_pixel_put(game->engine->mlx, game->engine->window,
			x_center - c->y, y_center + c->x, c->color);
		mlx_pixel_put(game->engine->mlx, game->engine->window,
			x_center + c->y, y_center - c->x, c->color);
		mlx_pixel_put(game->engine->mlx, game->engine->window,
			x_center - c->y, y_center - c->x, c->color);
		c->y++;
		if (c->p <= 0)
			c->p = c->p + 2 * c->y + 1;
		else
		{
			c->x--;
			c->p = c->p + 2 * c->y - 2 * c->x + 1;
		}
	}
}

void	draw_line(t_game *game, int x0, int y0, int x1, int y1, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	sx = (x0 < x1) ? 1 : -1;
	sy = (y0 < y1) ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	e2 = 0;
	while (1)
	{
		mlx_pixel_put(game->engine->mlx, game->engine->window, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
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

void	put_player(t_game *game, int x, int y)
{
	int	color;
	int	radius;
	int	line_length;
	int	end_x;
	int	end_y;

	color = 0x00FF00;
	radius = PLAYER_SIZE / 2;
	line_length = radius + 10;
	game->player->circle->color = 0x00FF00;
	draw_circle(game, x * MAP_SIZE + radius, y * MAP_SIZE + radius, radius);
	end_x = x * MAP_SIZE + radius + line_length * cos(game->player->angle);
	end_y = y * MAP_SIZE + radius - line_length * sin(game->player->angle);
	draw_line(game,
		x * MAP_SIZE + radius,
		y * MAP_SIZE + radius,
		end_x,
		end_y,
		color);
	game->player->x = x;
	game->player->y = y;
}
