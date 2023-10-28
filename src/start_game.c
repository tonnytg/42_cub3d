/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:53:48 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/27 21:11:33 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	expose_hook(t_game *game)
{
	render_game(game);
	return (0);
}

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
	printf("player x: %f\n", game->player->x);
	printf("player y: %f\n", game->player->y);
	printf("player angle: %f\n", game->player->angle);
	render_game(game);
	mlx_expose_hook(game->engine->window, expose_hook, game);
	mlx_hook(game->engine->window, 17, 0, (void *)exit_game, game);
	mlx_hook(game->engine->window, 2, 1L << 0, key_press, game);
	mlx_loop(game->engine->mlx);
	return (game);
}
