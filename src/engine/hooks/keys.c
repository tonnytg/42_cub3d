/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:38:24 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/13 13:39:56 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	key_press(int keycode, t_game *game)
{
	float move_speed = 5.0; // Ajuste conforme necessário
	float angle_speed = M_PI / 16; // Ajuste conforme necessário

	if (keycode == ESC)
	{
		exit_game(game);
	}
	else if (keycode == UP)
	{
		game->player->x += move_speed * cos(game->player->angle);
		game->player->y -= move_speed * sin(game->player->angle); // '-' porque o eixo y é invertido na tela
	}
	else if (keycode == DOWN)
	{
		game->player->x -= move_speed * cos(game->player->angle);
		game->player->y += move_speed * sin(game->player->angle);
	}
	else if (keycode == LEFT2)
	{
		game->player->x -= move_speed * sin(game->player->angle);
		game->player->y -= move_speed * cos(game->player->angle);
	}
	else if (keycode == RIGHT2)
	{
		game->player->x += move_speed * sin(game->player->angle);
		game->player->y += move_speed * cos(game->player->angle);
	}
	else if (keycode == LEFT)
	{
		game->player->angle -= angle_speed;
	}
	else if (keycode == RIGHT)
	{
		game->player->angle += angle_speed;
	}

	// Redesenhe a tela após a mudança
	mlx_clear_window(game->engine->mlx, game->engine->window);
	build_map(game);
	put_player(game, game->player->x, game->player->y);
	return (0);
}


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

int	key_press2(int keycode, t_game *game)
{
	printf("Key Pressed: %d\n", keycode);
	if (keycode == ESC)
	{
		printf("press ESC\n");
		exit_game(game);
	}
	else if (keycode == LEFT || keycode == LEFT2)
	{
		game->player->angle += M_PI / 16; // Gira 11.25 graus à esquerda
	}
	else if (keycode == RIGHT || keycode == RIGHT2)
	{
		game->player->angle -= M_PI / 16; // Gira 11.25 graus à direita
	}
	// Redesenhe a tela após a mudança
	mlx_clear_window(game->engine->mlx, game->engine->window);
	build_map(game);
	put_player(game, 10, 10);
	return (0);
}