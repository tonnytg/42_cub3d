/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:34:42 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/14 13:34:43 by antthoma         ###   ########.fr       */
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
				put_image(game, game->images->wall, column, line);
			if (game->map->grid[line][column] == 'C')
				put_image(game, game->images->collectible, column, line);
			if (game->map->grid[line][column] == 'E')
				put_image(game, game->images->exit, column, line);
			if (game->map->grid[line][column] == 'P')
				put_player(game, column, line);
			column++;
		}
		line++;
	}
	return (0);
}
