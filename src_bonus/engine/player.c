/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:35:12 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/29 09:45:57 by lbiasuz          ###   ########.fr       */
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
	l->plane.x = cos((game->player.angle + 90) * M_PI / 180.0);
	l->plane.y = sin((game->player.angle + 90) * M_PI / 180.0);
	l->id = 0;
}
