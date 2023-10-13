/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:38:24 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/13 05:58:56 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	key_press1(int keycode, t_game *game)
{
	printf("Key Pressed: %d\n", keycode);
	if (keycode == ESC)
	{
		printf("press ESC\n");
		exit_game(game);
	}
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	printf("Key Pressed: %d\n", keycode);
	if (keycode == ESC)
	{
		printf("press ESC\n");
		exit_game(game);
	}
	else if (keycode == LEFT)
	{
		game->player->angle += M_PI / 16; // Gira 11.25 graus à esquerda
	}
	else if (keycode == RIGHT)
	{
		game->player->angle -= M_PI / 16; // Gira 11.25 graus à direita
	}
	// Redesenhe a tela após a mudança
	mlx_clear_window(game->engine->mlx, game->engine->window);
	build_map(game);
	put_player(game, 10, 10);
	return (0);
}