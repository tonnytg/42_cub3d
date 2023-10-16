/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:30:45 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/16 02:38:00 by antthoma         ###   ########.fr       */
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
			game->engine->window, l->x0, l->y0, game->player->line->color);
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

void draw_line_fov1(t_game *game)
{
    t_player_line *l = game->player->line;
    set_value_to_draw_line(l);

    while (1)
    {
        if (l->x0 == l->x1 && l->y0 == l->y1)
		{
			break;	
		}

        if (l->x0 >= 0 && l->x0 < game->map->columns && l->y0 >= 0 && l->y0 < game->map->lines)
		{
            if (game->map->grid[l->y0][l->x0] == '1')
			{
				printf("houve colisão!\n");
				printf("x0: %d\n", l->x0);
				printf("y0: %d\n", l->y0);
            }
        } else
		{
			printf("fora do range\n");
            break;
        }
		mlx_pixel_put(game->engine->mlx, game->engine->window, l->x0, l->y0, game->player->line->color);

        l->e2 = l->err;

        if (l->e2 > -l->dx) {
            l->err -= l->dy;
            l->x0 += l->sx;
        }
        if (l->e2 < l->dy) {
            l->err += l->dx;
            l->y0 += l->sy;
        }
    }
}

int TILE = 16;

void draw_line_fov(t_game *game)
{
    t_player_line *l = game->player->line;
    set_value_to_draw_line(l);

    while (1)
    {
        if (l->x0 == l->x1 && l->y0 == l->y1)
        {
            break;	
        }

        int map_x = l->x0 / TILE;
        int map_y = l->y0 / TILE;

        if (map_x >= 0 && map_x < game->map->columns && map_y >= 0 && map_y < game->map->lines)
        {
            if (game->map->grid[map_y][map_x] == '1')
            {
                printf("houve colisão!\n");
                printf("x0: %d\n", l->x0);
                printf("y0: %d\n", l->y0);
                break;
            }
        } 
        else
        {
            printf("fora do range\n");
            break;
        }
        mlx_pixel_put(game->engine->mlx, game->engine->window, l->x0, l->y0, game->player->line->color);

        l->e2 = l->err;

        if (l->e2 > -l->dx) {
            l->err -= l->dy;
            l->x0 += l->sx;
        }
        if (l->e2 < l->dy) {
            l->err += l->dx;
            l->y0 += l->sy;
        }
    }
}


void calc_line_fov(t_game *game)
{
    t_player_line *l;

    l = game->player->line;
    printf("draw fov %p\n", game);
    // Obtenha as coordenadas finais da linha vermelha com base no ângulo do jogador
    double red_line_length = 550;  // Defina o comprimento da linha vermelha (ajuste conforme necessário)
    double player_angle = game->player->angle;
    int x0_red = l->x1; // Comece a linha vermelha no final da linha verde
    int y0_red = l->y1;
    int x1_red = x0_red + red_line_length * cos(player_angle);
    int y1_red = y0_red - red_line_length * sin(player_angle);

    // Desenhe a linha vermelha
    set_value_to_draw_line(l);
    l->x0 = x0_red;
    l->y0 = y0_red;
    l->x1 = x1_red;
    l->y1 = y1_red;
	game->player->line->color = 0xFF0000;
    draw_line_fov(game);
}