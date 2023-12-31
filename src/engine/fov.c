/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 01:22:26 by lbiasuz           #+#    #+#             */
/*   Updated: 2023/10/30 14:43:10 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_fov_line(t_fov_line *l)
{
	l->camera = 2 * l->id / (double) WIDTH - 1;
	l->ray.x = l->dir.x + l->plane.x * l->camera;
	l->ray.y = l->dir.y + l->plane.y * l->camera;
	l->map.x = (int) l->pos.x;
	l->map.y = (int) l->pos.y;
	l->dist.x = 100000000;
	if (l->ray.x != 0)
		l->dist.x = fabs(1 / l->ray.x);
	l->dist.y = 100000000;
	if (l->ray.y != 0)
		l->dist.y = fabs(1 / l->ray.y);
	l->step.x = (-1 * (l->ray.x < 0)) + (1 * (l->ray.x >= 0));
	if (l->ray.x < 0)
		l->side.x = (l->pos.x - l->map.x) * l->dist.x;
	else
		l->side.x = (l->map.x + 1.0 - l->pos.x) * l->dist.x;
	l->step.y = (-1 * (l->ray.y < 0)) + (1 * (l->ray.y >= 0));
	if (l->ray.y < 0)
		l->side.y = (l->pos.y - l->map.y) * l->dist.y;
	else
		l->side.y = (l->map.y + 1.0 - l->pos.y) * l->dist.y;
}

void	fov_line_distance(t_game *game, t_fov_line *l)
{
	while (game->map->grid[(int) l->map.y][(int) l->map.x] != '1')
	{
		if (l->side.x < l->side.y)
		{
			l->side.x += l->dist.x;
			l->map.x += l->step.x;
			l->wall_side = (('W' * (l->step.x < 0)) + ('E' * (l->step.x > 0)));
		}
		else
		{
			l->side.y += l->dist.y;
			l->map.y += l->step.y;
			l->wall_side = (('N' * (l->step.y < 0)) + ('S' * (l->step.y > 0)));
		}
	}
	if (l->wall_side == 'W' || l->wall_side == 'E')
		l->len = HEIGHT / (l->side.x - l->dist.x);
	else
		l->len = HEIGHT / (l->side.y - l->dist.y);
}
