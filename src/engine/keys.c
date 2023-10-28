/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:38:24 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/28 13:06:10 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	press_up(t_game *game)
{
	game->player.x += MOVE_SPEED * cos(game->player.angle * (M_PI / 180.0));
	game->player.y += MOVE_SPEED * sin(game->player.angle * (M_PI / 180.0));
}

void	press_down(t_game *game)
{
	game->player.x -= MOVE_SPEED * cos(game->player.angle * (M_PI / 180.0));
	game->player.y -= MOVE_SPEED * sin(game->player.angle * (M_PI / 180.0));
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		exit_game(game);
	else if (keycode == UP || keycode == UP2)
		press_up(game);
	else if (keycode == DOWN || keycode == DOWN2)
		press_down(game);
	else if (keycode == RIGHT || keycode == RIGHT2)
	{
		game->player.angle += TURN_SPEED;
		if (game->player.angle >= 360.0)
			game->player.angle -= 360.0;
	}
	else if (keycode == LEFT || keycode == LEFT2)
	{
		game->player.angle -= TURN_SPEED;
		if (game->player.angle < 0)
			game->player.angle += 360.0;
	}
	render_game(game);
	return (0);
}
