/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:35:12 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/16 02:02:21 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	put_player(t_game *game, int x, int y)
{
	int	radius;
	int	line_length;
	int	end_x;
	int	end_y;

	radius = PLAYER_SIZE / 2;
	line_length = radius + 10;
	game->player->circle->color = 0x00FF00;
	game->player->circle->x_center = x * 2 + radius;
	game->player->circle->y_center = y * 2 + radius;
	game->player->circle->radius = radius;
	draw_circle(game);
	end_x = x * 2 + radius + line_length * cos(game->player->angle);
	end_y = y * 2 + radius - line_length * sin(game->player->angle);
	game->player->line->x0 = x * 2 + radius;
	game->player->line->y0 = y * 2 + radius;
	game->player->line->x1 = end_x;
	game->player->line->y1 = end_y;
	game->player->circle->color = 0x00FF00;
	draw_line(game);
	game->player->x = x;
	game->player->y = y;
	calc_line_fov(game);
}
