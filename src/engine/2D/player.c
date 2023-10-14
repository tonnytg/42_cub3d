/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:35:12 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/14 14:07:15 by antthoma         ###   ########.fr       */
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
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2;
	int e2;

	while (1)
	{
		mlx_pixel_put(game->engine->mlx, game->engine->window, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break;
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
	int color = 0x00FF00; // Cor verde para o jogador
	int radius = PLAYER_SIZE / 2; // Raio da bolinha
	int line_length = radius + 10; // Comprimento da linha indicadora

	// Desenha o círculo do jogador
	game->player->circle->color = 0x00FF00;
	draw_circle(game, x * MAP_SIZE + radius, y * MAP_SIZE + radius, radius);
	// Desenha a linha indicadora com base no ângulo
	int end_x = x * MAP_SIZE + radius + line_length * cos(game->player->angle);
	int end_y = y * MAP_SIZE + radius - line_length * sin(game->player->angle); // '-' porque o eixo y é invertido na tela
	draw_line(game, 
			  x * MAP_SIZE + radius, 
			  y * MAP_SIZE + radius, 
			  end_x, 
			  end_y, 
			  color);
	game->player->x = x;
	game->player->y = y;
}
