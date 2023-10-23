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

double	ft_abs(double number)
{
	if (number < 0)
		return (number * -1);
	return (number);
}

void	put_player(t_game *game)
{
	for (int index = 0; index < FOV; index++)
	{
		game->player->line[index].line_length = 0;
		game->player->line[index].beg.x = game->player->x;
		game->player->line[index].beg.y = game->player->y;
		game->player->line[index].end.x = game->player->x + 10 * cos(game->player->angle * (M_PI / 180.0));
		game->player->line[index].end.y = game->player->y + 10 * sin(game->player->angle * (M_PI / 180.0));
	}
}
