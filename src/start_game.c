/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:53:48 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/28 13:07:05 by lbiasuz          ###   ########.fr       */
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
	game->mlx = mlx_init();
	if (!game->mlx)
		return (NULL);
	game->window = mlx_new_window(game->mlx,
			WIDTH,
			HEIGHT,
			"cub3D");
	load_images(game);
	printf("player x: %f\n", game->player.x);
	printf("player y: %f\n", game->player.y);
	printf("player angle: %f\n", game->player.angle);
	render_game(game);
	mlx_expose_hook(game->window, expose_hook, game);
	mlx_hook(game->window, 17, 0, (void *)exit_game, game);
	mlx_hook(game->window, 2, 1L << 0, key_press, game);
	mlx_loop(game->mlx);
	return (game);
}
