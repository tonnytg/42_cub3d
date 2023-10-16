/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:38:24 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/16 23:42:49 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	render_map_2d(t_game *game)
{
	mlx_clear_window(game->engine->mlx, game->engine->window);
	build_map(game);
	put_player(game, game->player->x, game->player->y);
}


int	key_press(int keycode, t_game *game)
{
	float	move_speed;
	float	angle_speed;

	move_speed = 2.0;
	angle_speed = M_PI / 10;
	if (keycode == ESC)
		exit_game(game);
	else if (keycode == UP || keycode == UP2)
	{
		game->player->x += move_speed * cos(game->player->angle);
		game->player->y -= move_speed * sin(game->player->angle);
	}
	else if (keycode == DOWN || keycode == DOWN2)
	{
		game->player->x -= move_speed * cos(game->player->angle);
		game->player->y += move_speed * sin(game->player->angle);
	}
	else if (keycode == LEFT || keycode == LEFT2)
		game->player->angle += angle_speed;
	else if (keycode == RIGHT || keycode == RIGHT2)
		game->player->angle -= angle_speed;
	render_map_2d(game);
	return (0);
}