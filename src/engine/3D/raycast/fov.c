/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 01:22:26 by lbiasuz           #+#    #+#             */
/*   Updated: 2023/10/28 11:38:41 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	calc_line_fov(t_game *game)
{
	int			fov_id;
	double		start_angle;
	double		angle_increment;
	t_fov_line	*l;

	fov_id = 0;
	start_angle = game->player->angle * (M_PI / 180.0) - \
		(FOV / 2) * (M_PI / 180.0);
	angle_increment = (double) FOV / FOV * (M_PI / 180.0);
	printf("angle_increment: %f \n", angle_increment);
	while (fov_id < FOV)
	{
		l = &game->player->line[fov_id];
		l->angle = start_angle;
		l->end.x = l->beg.x + FOV_LENGTH * cos(start_angle);
		l->end.y = l->beg.y + FOV_LENGTH * sin(start_angle);
		calc_fov_line_distance(game, fov_id);
		start_angle += angle_increment;
		fov_id++;
	}
}

void	set_value_to_draw_line(t_fov_line *l)
{
	l->dist.x = fabs(l->end.x - l->beg.x);
	l->dist.y = fabs(l->end.y - l->beg.y);
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
}

// calcula a distancia do raio até colidir com alguma parede
void	calc_fov_line_distance(t_game *game, int fov_id)
{
	t_fov_line	*l;
	int			map_x;
	int			map_y;

	l = &game->player->line[fov_id];
	set_value_to_draw_line(l);
	while (l->beg.x != l->end.x || l->beg.y != l->end.y)
	{
		l->len++;
		if (l->err > -l->dist.x)
		{
			l->err -= l->dist.y;
			l->beg.x += l->step.x;
			l->wall_side = (l->step.y > 0) ? 'E' : 'W';
		}
		if (l->err < l->dist.y)
		{
			l->err += l->dist.x;
			l->beg.y += l->step.y;
			l->wall_side = (l->step.x > 0) ? 'S' : 'N';
		}
		map_x = l->beg.x / TILE_SIZE;
		map_y = l->beg.y / TILE_SIZE;
		if (map_x >= 0 && map_x < game->map->columns && map_y >= 0
			&& map_y < game->map->lines && game->map->grid[map_y][map_x] == '1')
			break ;
	}
}
