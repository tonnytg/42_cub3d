/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:54:42 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/10 18:24:39 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_game	*clean_map(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->map->lines)
    {
        free(game->map->grid[i]);
		i++;
    }
	free(game->map->grid);
    return	(game);
}

int	clean_struct(t_game *game)
{
	clean_map(game);
	if (game->engine)
		free(game->engine);
	if (game->map)
		free(game->map);
	if (game)
		free(game);
	return (0);
}

t_game	*finish_game(t_game *game)
{
	printf("finish game %p!\n", game);
	clean_struct(game);
	return (NULL);
}
