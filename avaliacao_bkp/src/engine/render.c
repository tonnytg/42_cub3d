/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:29:54 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/30 14:43:05 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	render_game(t_game *game)
{
	put_player(game);
	draw_background(game);
	while (game->player.line.id < WIDTH)
	{
		init_fov_line(&game->player.line);
		fov_line_distance(game, &game->player.line);
		draw_fov(game, game->player.line.id, HEIGHT - game->player.line.len);
		game->player.line.id++;
	}
	if (MINIMAP)
	{
		draw_player(game);
		draw_map(game);
	}
	return (0);
}
