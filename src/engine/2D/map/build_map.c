/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:34:42 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/28 13:56:11 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	build_map(t_game *game)
{
	int	column;
	int	line;

	line = 0;
	while (line < game->map->lines)
	{
		column = 0;
		while (column < game->map->columns)
		{
			if (game->map->grid[line][column] == '1')
				put_image(game, game->images->wall_2d, column, line);
			column++;
		}
		line++;
	}
	return (0);
}

void	put_image(t_game *game, int *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx,
		game->window,
		image,
		x * TILE_SIZE,
		y * TILE_SIZE);
}
