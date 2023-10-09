/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:53:48 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/09 12:42:53 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_game	*start_game(t_game *game)
{
	printf("start game %p!\n", game);

	game->engine->width = PIXEL_SIZE * game->engine->count_columns;
	game->engine->height = PIXEL_SIZE * game->engine->count_lines;

	game->engine->mlx = mlx_init();
	if (!game->engine->mlx)
		return (NULL);
	mlx_get_screen_size(game->engine->mlx, &game->engine->screen_width, &game->engine->screen_height);
	if ((game->engine->width > game->engine->screen_width)
		|| (game->engine->height > game->engine->screen_height))
		return (NULL);
	game->engine->window = mlx_new_window(game->engine->mlx, game->engine->width, game->engine->height, "cub3D");
	if (!game->engine->window || !game->engine->mlx)
		return (NULL);
	return (game);
}
