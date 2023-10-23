/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:53:48 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/21 17:11:15 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_game	*start_game(t_game *game)
{
	if (game == NULL)
		return (NULL);
	game->engine->width = WIDTH;
	game->engine->height = HEIGHT;
	game->engine->mlx = mlx_init();
	if (!game->engine->mlx)
		return (NULL);
	game->engine->window = mlx_new_window(game->engine->mlx,
			game->engine->width,
			game->engine->height,
			"cub3D");
	load_images(game);
	printf("player x: %d\n", game->player->x);
	printf("player y: %d\n", game->player->y);
	printf("player angle: %f\n", game->player->angle);
	render_game(game);
	mlx_hook(game->engine->window, 17, 0, (void *)exit_game, game);
	mlx_hook(game->engine->window, 2, 1L << 0, key_press, game);
	mlx_loop(game->engine->mlx);
	return (game);
}