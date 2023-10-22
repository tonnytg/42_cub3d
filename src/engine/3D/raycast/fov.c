/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 01:22:26 by lbiasuz           #+#    #+#             */
/*   Updated: 2023/10/21 22:08:53 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

double	rad(int	d)
{
	return (d * (M_PI / 180));
}

int	ang(int n)
{
	if (n > 359)
		n -= 360;
	else if (n <= 0)
		n += 360;
	return (n);
}

double	hip(t_fov_line	line)
{
	return (cos(line.angle) * (line.end.x - line.beg.x)
			- sin(line.angle) * (line.end.y - line.beg.y));
}

int	set_direction_vertical(t_fov_line *l)
{
	float	t;

	t = tan(rad(l->angle));
	if (cos(rad(l->angle)) > 0.001)
	{
		l->beg.x = (int) ((l->beg.x>>TILE_DP)<<TILE_DP) + TILE_SIZE;
		l->beg.y =  l->beg.x-l->beg.x * t + l->beg.y;
		l->step.x = TILE_SIZE;
		l->step.y = -TILE_SIZE * t;
	}
	else if (cos(rad(l->angle)) < -0.001)
	{
		l->beg.x = (int) ((l->beg.x>>TILE_DP)<<TILE_DP) - 0.0001;
		l->beg.y =  l->beg.x-l->end.x * t + l->beg.y;
		l->step.x = -TILE_SIZE;
		l->step.y = TILE_SIZE * t;
	}
	else
		return (0);
	return (8);
}

int	set_direction_horizontal(t_fov_line *l)
{
	float	t;

	t = 1.0 / tan(rad(l->angle));
	if (sin(rad(l->angle)) > 0.001)
	{
		l->beg.y = (int) ((l->beg.y>>TILE_DP)<<TILE_DP) + TILE_SIZE;
		l->beg.x =  l->beg.y-l->beg.y * t + l->beg.x;
		l->step.y = -TILE_SIZE;
		l->step.x = TILE_SIZE * t;
	}
	else if (sin(rad(l->angle)) < -0.001)
	{
		l->beg.y = (int) ((l->beg.y>>TILE_DP)<<TILE_DP) - 0.0001;
		l->beg.x =  l->beg.y-l->end.x * t + l->beg.x;
		l->step.y = TILE_SIZE;
		l->step.x = -TILE_SIZE * t;
	}
	else
		return (0);
	return (8);
}

int	verify_hit_wall(t_game *game, t_fov_line *l, int dof)
{
	while (dof > 0)
	{
		printf("%d %d \n", l->end.y / TILE_SIZE, l->end.x / TILE_SIZE);
		if (l->end.y / TILE_SIZE >= 0 && l->end.x / TILE_SIZE >= 0
			&& l->end.y / TILE_SIZE < game->map->lines
			&& l->end.x / TILE_SIZE < game->map->columns
			&& game->map->grid[l->end.y / TILE_SIZE][l->end.x / TILE_SIZE] == '1')
			return (hip(*l));
		else
		{
			l->end.x += l->step.x;
			l->end.y += l->step.y;
		}
		dof--;
	}
	return (0);
}

void calc_fov_line_distance(t_game *game, t_fov_line *l)
{
	double	hit_v;
	double	hit_h;

	hit_v = verify_hit_wall(game, l, set_direction_vertical(l));
	hit_h = verify_hit_wall(game, l, set_direction_vertical(l));
	if (hit_v < hit_v)
		l->line_length = hit_v;
	else
		l->line_length = hit_h;
	l->line_length = l->line_length * cos(rad(l->angle - game->player->angle));
}

void calc_line_fov(t_game *game)
{
	int fov_id;
	int start_angle;
	int end_angle;
	t_fov_line	*l;

	fov_id = 0;
	start_angle = game->player->angle - (FOV / 2);
	end_angle = game->player->angle + (FOV / 2);
	while(start_angle <= end_angle)
	{
		l = &game->player->line[fov_id];
		l->id = fov_id;
		l->beg.x = game->player->x;
		l->beg.y = game->player->y;
		l->angle = start_angle;
		l->color = 0xFFFF00;
		calc_fov_line_distance(game, l);
		start_angle++;
		fov_id++;
	}
}