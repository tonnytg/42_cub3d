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

void	render_map_2d(t_game *game)
{
	mlx_clear_window(game->engine->mlx, game->engine->window);
	// draw_background(game);
	build_map(game);
	put_player(game, game->player->x, game->player->y);
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
		game->player->y += MOVE_SPEED * sin(game->player->angle);
	}
	else if (keycode == DOWN || keycode == DOWN2)
	{
		game->player->x -= MOVE_SPEED * cos(game->player->angle);
		game->player->y -= MOVE_SPEED * sin(game->player->angle);
	}
	else if (keycode == RIGHT || keycode == RIGHT2)
		game->player->angle += angle_speed;
	else if (keycode == LEFT || keycode == LEFT2)
		game->player->angle -= angle_speed;
	render_map_2d(game);
	return (0);
}