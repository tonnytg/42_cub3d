/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:30:45 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/14 23:45:30 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	set_value_to_draw_line(t_player_line *l)
{
	l->dx = abs(l->x1 - l->x0);
	l->dy = abs(l->y1 - l->y0);
	if (l->x0 < l->x1)
		l->sx = 1;
	else
		l->sx = -1;
	if (l->y0 < l->y1)
		l->sy = 1;
	else
		l->sy = -1;
	if (l->dx > l->dy)
		l->err = l->dx / 2;
	else
		l->err = -l->dy / 2;
	l->e2 = 0;
}

/* Bresenham Algorithms to draw line*/
/*
	dx: A diferença absoluta entre as coordenadas x
		inicial e final da linha. Representa a largura horizontal da linha.
	dy: A diferença absoluta entre as coordenadas y
		inicial e final da linha. Representa a altura vertical da linha.
	sx: Direção do passo no eixo x. Pode ser 1
		(para a direita) ou -1 (para a esquerda).
	sy: Direção do passo no eixo y. Pode ser 1
		(para cima) ou -1 (para baixo).
	err: O erro acumulado ao desenhar a linha.
		É usado para determinar quando mover
		a linha verticalmente ou horizontalmente.
	e2: Uma variável temporária usada para armazenar um valor
		intermediário do erro.
*/
void	draw_line(t_game *game)
{
	t_player_line	*l;

	l = game->player->line;
	set_value_to_draw_line(l);
	while (1)
	{
		mlx_pixel_put(game->engine->mlx,
			game->engine->window, l->x0, l->y0, game->player->circle->color);
		if (l->x0 == l->x1 && l->y0 == l->y1)
			break ;
		l->e2 = l->err;
		if (l->e2 > -l->dx)
		{
			l->err -= l->dy;
			l->x0 += l->sx;
		}
		if (l->e2 < l->dy)
		{
			l->err += l->dx;
			l->y0 += l->sy;
		}
	}
}
