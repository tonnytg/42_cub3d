/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:35:12 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/23 20:52:48 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	put_player(t_game *game)
{
	int	index;

	index = 0;
	while (index < FOV)
	{
		game->player->line[index].line_length = 0;
		game->player->line[index].beg.x = game->player->x;
		game->player->line[index].beg.y = game->player->y;
		game->player->line[index].end.x = game->player->x + 10 * \
			cos(game->player->angle * (M_PI / 180.0));
		game->player->line[index].end.y = game->player->y + 10 * \
			sin(game->player->angle * (M_PI / 180.0));
		index++;
	}
}
