/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:28:03 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/22 13:56:45 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	draw_floor(t_game *game)
{
	t_game_background	*b;

	b = game->map->background;
	b->top_half_height = game->engine->height / 2;
	b->floor.img = mlx_new_image(game->engine->mlx, game->engine->width,
			b->top_half_height);
	b->floor.addr = mlx_get_data_addr(b->floor.img, &b->floor.bits_per_pixel,
			&b->floor.line_length, &b->floor.endian);
	b->y = 0;
	while (b->y < b->top_half_height)
	{
		b->x = 0;
		while (b->x < game->engine->width)
		{
			my_mlx_pixel_put(&b->floor, b->x, b->y, game->images->sky_color);
			b->x++;
		}
		b->y++;
	}
	mlx_put_image_to_window(game->engine->mlx, game->engine->window,
		b->floor.img, 0, 0);
	return (0);
}

int	draw_sky(t_game *game)
{
	t_game_background	*b;

	b = game->map->background;
	b->bottom_half_height = game->engine->height - b->top_half_height;
	b->sky.img = mlx_new_image(game->engine->mlx, game->engine->width,
			b->bottom_half_height);
	b->sky.addr = mlx_get_data_addr(b->sky.img, &b->sky.bits_per_pixel,
			&b->sky.line_length, &b->sky.endian);
	b->y = b->top_half_height;
	while (b->y < game->engine->height)
	{
		b->x = 0;
		while (b->x < game->engine->width)
		{
			my_mlx_pixel_put(&b->sky, b->x, b->y - b->top_half_height,
				game->images->floor_color);
			b->x++;
		}
		b->y++;
	}
	mlx_put_image_to_window(game->engine->mlx, game->engine->window,
		b->sky.img, 0, b->top_half_height);
	return (0);
}

int	draw_background(t_game *game)
{
	t_game_background	*b;

	b = game->map->background;
	draw_floor(game);
	draw_sky(game);
	mlx_destroy_image(game->engine->mlx, b->floor.img);
	mlx_destroy_image(game->engine->mlx, b->sky.img);
	return (0);
}
