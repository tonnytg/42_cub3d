/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:34:42 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/15 22:59:40 by antthoma         ###   ########.fr       */
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
			column++;
		}
		line++;
	}
	return (0);
}
