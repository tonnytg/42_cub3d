/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:28:03 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/30 14:36:56 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	draw_floor(t_game *game)
{
	int	x;
	int	y;

	game->floor.img = mlx_new_image(game->mlx, WIDTH,
			HEIGHT / 2);
	game->floor.addr = mlx_get_data_addr(game->floor.img, &game->floor.bpp,
			&game->floor.len, &game->floor.endian);
	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(&game->floor, x, y, game->images->sky_color);
			x++;
		}
		y++;
	}
	return (0);
}

int	draw_sky(t_game *game)
{
	int	x;
	int	y;

	game->sky.img = mlx_new_image(game->mlx, WIDTH,
			HEIGHT - (HEIGHT / 2));
	game->sky.addr = mlx_get_data_addr(game->sky.img, &game->sky.bpp,
			&game->sky.len, &game->sky.endian);
	y = (HEIGHT / 2);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(&game->sky, x, y - (HEIGHT / 2),
				game->images->floor_color);
			x++;
		}
		y++;
	}
	return (0);
}

int	draw_background(t_game *game)
{
	if (!game->floor.img)
		draw_floor(game);
	mlx_put_image_to_window(game->mlx, game->window,
		game->floor.img, 0, 0);
	if (!game->sky.img)
		draw_sky(game);
	mlx_put_image_to_window(game->mlx, game->window,
		game->sky.img, 0, HEIGHT / 2);
	return (0);
}
