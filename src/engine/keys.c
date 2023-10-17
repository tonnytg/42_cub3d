/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:38:24 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/17 23:20:14 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	render_map_2d(t_game *game)
{
	mlx_clear_window(game->engine->mlx, game->engine->window);
	build_map(game);
	put_player(game, game->player->x, game->player->y);
}

void	render(t_game *game)
{
	mlx_clear_window(game->engine->mlx, game->engine->window);
}

int	key_press(int keycode, t_game *game)
{
	float	angle_speed;

	angle_speed = M_PI / TURN_SPEED;
	if (keycode == ESC)
		exit_game(game);
	else if (keycode == UP || keycode == UP2)
	{
		game->player->x += MOVE_SPEED * cos(game->player->angle);
		game->player->y -= MOVE_SPEED * sin(game->player->angle);
	}
	else if (keycode == DOWN || keycode == DOWN2)
	{
		game->player->x -= MOVE_SPEED * cos(game->player->angle);
		game->player->y += MOVE_SPEED * sin(game->player->angle);
	}
	else if (keycode == LEFT || keycode == LEFT2)
		game->player->angle += angle_speed;
	else if (keycode == RIGHT || keycode == RIGHT2)
		game->player->angle -= angle_speed;
	render_map_2d(game);
	return (0);
}