/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:35:12 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/28 23:53:32 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	put_player(t_game *game)
{
	t_fov_line	*l;

	l = &game->player.line;
	l->pos.x = game->player.x;
	l->pos.y = game->player.y;
	l->dir.x = cos(game->player.angle * M_PI / 180.0);
	l->dir.y = sin(game->player.angle * M_PI / 180.0);
	l->plane.x = 0.0;
	l->plane.y = 0.66;
	l->id = 0;
}
