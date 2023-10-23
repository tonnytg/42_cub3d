/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:38:24 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/23 21:00:58 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

double round_to_n_decimal_places(double value, int n) {
    double multiplier = pow(10.0, n);
    return round(value * multiplier) / multiplier;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		exit_game(game);
	else if (keycode == UP || keycode == UP2)
	{
		game->player->x += MOVE_SPEED * cos(game->player->angle * (M_PI / 180.0));
		game->player->y += MOVE_SPEED * sin(game->player->angle * (M_PI / 180.0));
	}
	else if (keycode == DOWN || keycode == DOWN2)
	{
		game->player->x -= MOVE_SPEED * cos(game->player->angle * (M_PI / 180.0));
		game->player->y -= MOVE_SPEED * sin(game->player->angle * (M_PI / 180.0));
	}
	else if (keycode == RIGHT || keycode == RIGHT2) {
		game->player->angle += TURN_SPEED;
		if (game->player->angle >= 360.0)
			game->player->angle -= 360.0;
	}
	else if (keycode == LEFT || keycode == LEFT2) {
		game->player->angle -= TURN_SPEED;
		if (game->player->angle < 0)
			game->player->angle += 360.0;
	}
	render_game(game);
	return (0);
}