/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:38:24 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/21 17:11:11 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	key_press(int keycode, t_game *game)
{
	game->i++;
	if (keycode == ESC)
		exit_game(game);
	else if (keycode == UP || keycode == UP2)
	{
		printf("key up pressed\n");
		game->player->x += MOVE_SPEED * cos(game->player->angle);
		game->player->y += MOVE_SPEED * sin(game->player->angle);
	}
	else if (keycode == DOWN || keycode == DOWN2)
	{
		printf("key down pressed\n");
		game->player->x -= MOVE_SPEED * cos(game->player->angle);
		game->player->y -= MOVE_SPEED * sin(game->player->angle);
	}
	else if (keycode == RIGHT || keycode == RIGHT2)
	{
		printf("key right pressed\n");
		game->player->angle += TURN_SPEED;
	}
	else if (keycode == LEFT || keycode == LEFT2)
	{
		printf("key left pressed\n");
		game->player->angle -= TURN_SPEED;
	}
	// render_map_2d(game);
	return (0);
}