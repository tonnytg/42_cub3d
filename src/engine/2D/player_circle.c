/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_circle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:30:59 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/14 23:45:23 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw_cicle_in_pixel(t_game *game, t_player_circle *c)
{
	mlx_pixel_put(game->engine->mlx, game->engine->window,
		c->x_center + c->x, c->y_center + c->y, c->color);
	mlx_pixel_put(game->engine->mlx, game->engine->window,
		c->x_center - c->x, c->y_center + c->y, c->color);
	mlx_pixel_put(game->engine->mlx, game->engine->window,
		c->x_center + c->x, c->y_center - c->y, c->color);
	mlx_pixel_put(game->engine->mlx, game->engine->window,
		c->x_center - c->x, c->y_center - c->y, c->color);
	mlx_pixel_put(game->engine->mlx, game->engine->window,
		c->x_center + c->y, c->y_center + c->x, c->color);
	mlx_pixel_put(game->engine->mlx, game->engine->window,
		c->x_center - c->y, c->y_center + c->x, c->color);
	mlx_pixel_put(game->engine->mlx, game->engine->window,
		c->x_center + c->y, c->y_center - c->x, c->color);
	mlx_pixel_put(game->engine->mlx, game->engine->window,
		c->x_center - c->y, c->y_center - c->x, c->color);
}

/* Bresenham Algorithms to draw circle*/
/*
	x_center e y_center: São as coordenadas do centro do círculo.
	x e y: São as coordenadas atuais do pixel sendo desenhado.
		Durante o algoritmo, você só precisa calcular os pixels
		para um oitavo do círculo (devido à simetria do círculo) e,
		em seguida, refletir esses pixels para os outros sete oitavos.
	p: É a decisão do parâmetro usado para determinar
		o próximo pixel a ser desenhado. Se p for menor ou igual a zero,
		o próximo pixel é diretamente acima do pixel atual. Caso contrário,
		é acima e à esquerda.
	radius: É o raio do círculo.
	color: É a cor do círculo.
*/
void	draw_circle(t_game *game)
{
	t_player_circle	*c;

	c = game->player->circle;
	c->x = c->radius;
	c->y = 0;
	c->p = 1 - c->radius;
	while (c->x >= c->y)
	{
		draw_cicle_in_pixel(game, c);
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
