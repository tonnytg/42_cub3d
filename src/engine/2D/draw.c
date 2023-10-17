/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:06:54 by lbiasuz           #+#    #+#             */
/*   Updated: 2023/10/17 23:15:31 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void draw_box(t_game *game, int fov_id, int line_length)
{
	int x = fov_id * (game->engine->width / FOV);
	int y = (game->engine->height / 2) - (line_length / 2);

	while (x < fov_id * (game->engine->width / FOV) + (game->engine->width / 60))
	{
		y = (game->engine->height / 2) - (line_length / 2);
		while (y < line_length)
		{
			mlx_pixel_put(game->engine->mlx, game->engine->window, x, y, 0x000FF);
			y++;
		}
		x++;
	}
}

void draw_line_fov(t_game *game, double fov_id)
{
	int line_length = 0;
	t_player_line *l = game->player->line;

	set_value_to_draw_line(l);

	while (l->beg.x != l->end.x || l->beg.y != l->end.y)
	{
		int map_x = l->beg.x / TILE_SIZE;
		int map_y = l->beg.y / TILE_SIZE;

		if (map_x >= 0 && map_x < game->map->columns && map_y >= 0 && map_y < game->map->lines)
		{
			if (game->map->grid[map_y][map_x] == '1')
			{
				draw_box(game, fov_id, ((game->engine->height / 2) - line_length));

				printf("houve colisão!\n");
				printf("beg.x: %d\n", l->beg.x);
				printf("beg.y: %d\n", l->beg.y);

				break;
			}
		}
		line_length++;

		mlx_pixel_put(game->engine->mlx, game->engine->window, l->beg.x, l->beg.y, game->player->line->color);

		l->e2 = l->err;

		if (l->e2 > -l->dist.x) {
			l->err -= l->dist.y;
			l->beg.x += l->step.x;
		}
		if (l->e2 < l->dist.y) {
			l->err += l->dist.x;
			l->beg.y += l->step.y;
		}
	}
}
