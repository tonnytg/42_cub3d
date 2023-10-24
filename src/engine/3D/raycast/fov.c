/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 01:22:26 by lbiasuz           #+#    #+#             */
/*   Updated: 2023/10/23 21:01:13 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void calc_line_fov(t_game *game) {
    int fov_id = 0;
    double start_angle, end_angle, angle_increment;
    t_fov_line *l;

    start_angle = game->player->angle * (M_PI / 180.0) - (FOV / 2) * (M_PI / 180.0);
    end_angle = game->player->angle * (M_PI / 180.0) + (FOV / 2) * (M_PI / 180.0);
    angle_increment = (double)FOV / FOV * (M_PI / 180.0); // Adicionado

    start_angle = fmod(start_angle + 2 * M_PI, 2 * M_PI);
    end_angle = fmod(end_angle + 2 * M_PI, 2 * M_PI);

    while(fov_id < FOV) {
        l = &game->player->line[fov_id];
        l->angle = start_angle;
        l->end.x = l->beg.x + FOV_LENGTH * cos(start_angle);
        l->end.y = l->beg.y + FOV_LENGTH * sin(start_angle);
        l->color = 0xFFFF00;
        calc_fov_line_distance(game, fov_id);
        start_angle += angle_increment;

        start_angle = fmod(start_angle + 2 * M_PI, 2 * M_PI);
        fov_id++;
    }
}

void	set_value_to_draw_line(t_fov_line *l)
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

// calcula a distancia do raio até colidir com alguma parede
void calc_fov_line_distance(t_game *game, int fov_id)
{
	t_fov_line *l;
	char wall_side;

	l = &game->player->line[fov_id];
	set_value_to_draw_line(l);
	while (l->beg.x != l->end.x || l->beg.y != l->end.y)
	{
		int map_x = l->beg.x / TILE_SIZE;
		int map_y = l->beg.y / TILE_SIZE;
		l->line_length++;
		l->e2 = l->err;
		if (l->e2 > -l->dist.x) {
			l->err -= l->dist.y;
			l->beg.x += l->step.x;

			wall_side = (l->step.x > 0) ? 'E' : 'W';
		}
		if (l->e2 < l->dist.y) {
			l->err += l->dist.x;
			l->beg.y += l->step.y;

			wall_side = (l->step.y > 0) ? 'S' : 'N';
		}
		if (map_x >= 0 && map_x < game->map->columns && map_y >= 0
			&& map_y < game->map->lines && game->map->grid[map_y][map_x] == '1')
		{
			// interrompe o raio se houver colisão
			l->wall_side = wall_side;
			break;
		}		
	}
}