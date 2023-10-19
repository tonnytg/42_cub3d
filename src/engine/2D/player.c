/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:35:12 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/19 06:19:47 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	put_player(t_game *game, int x, int y)
{
	for (int index = 0; index < FOV; index++)
	{
		game->player->line[index].line_length = 0;
		game->player->line[index].beg.x = x;
		game->player->line[index].beg.y = y;
		game->player->line[index].end.x = x * 2 + 10 * cos(game->player->angle);
		game->player->line[index].end.y = y * 2 - 10 * sin(game->player->angle);
	}
	game->player->x = x;
	game->player->y = y;
	calc_line_fov(game);
	for (int index = 0; index < FOV; index++)
		draw_box(game, index, (game->engine->height / 2 - game->player->line[index].line_length * cos(game->player->angle - game->player->line[index].angle)));
}
