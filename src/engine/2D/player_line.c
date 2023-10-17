/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:30:45 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/17 23:10:02 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

/* Bresenham Algorithms to draw line*/
/*
	dist.x: A diferença absoluta entre as coordenadas x
		inicial e final da linha. Representa a largura horizontal da linha.
	dist.y: A diferença absoluta entre as coordenadas y
		inicial e final da linha. Representa a altura vertical da linha.
	step.x: Direção do passo no eixo x. Pode ser 1
		(para a direita) ou -1 (para a esquerda).
	step.y: Direção do passo no eixo y. Pode ser 1
		(para cima) ou -1 (para baixo).
	err: O erro acumulado ao desenhar a linha.
		É usado para determinar quando mover
		a linha verticalmente ou horizontalmente.
	e2: Uma variável temporária usada para armazenar um valor
		intermediário do erro.
*/

void	set_value_to_draw_line(t_player_line *l)
{
	l->dist.x = abs(l->end.x - l->beg.x);
	l->dist.y = abs(l->end.y - l->beg.y);
	if (l->beg.x < l->end.x)
		l->step.x = 1;
	else
		l->step.x = -1;
	if (l->beg.y < l->end.y)
		l->step.y = 1;
	else
		l->step.y = -1;
	if (l->dist.x > l->dist.y)
		l->err = l->dist.x / 2;
	else
		l->err = -l->dist.y / 2;
	l->e2 = 0;
}

void calc_line_fov(t_game *game)
{
	double fov_id = 0;
	double angle_increment = 0.5;
	double start_angle = game->player->angle - (FOV / 2) * (M_PI / 180.0); // converte graus para radianos
	double end_angle = game->player->angle + (FOV / 2) * (M_PI / 180.0);

	int x0_red = game->player->line->beg.x;
	int y0_red = game->player->line->beg.y;

	for (double current_angle = start_angle; current_angle <= end_angle; current_angle += angle_increment * (M_PI / 180.0)) {
		int x1_red = x0_red + FOV_LENGTH * cos(current_angle);
		int y1_red = y0_red - FOV_LENGTH * sin(current_angle); // lembre-se, a direção Y é invertida!

		game->player->line->beg.x = x0_red;
		game->player->line->beg.y = y0_red;
		game->player->line->end.x = x1_red;
		game->player->line->end.y = y1_red;
		game->player->line->color = 0xFFFF00; // cor vermelha

		draw_line_fov(game, fov_id);
		fov_id += angle_increment;
	}
}
