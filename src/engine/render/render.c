/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:29:54 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/22 20:29:55 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	render_game(t_game *game)
{
	// mlx_clear_window(game->engine->mlx, game->engine->window);
	// build_map(game);
	// put_player(game, game->player->x, game->player->y);
	draw_background(game);
	// game->engine->dda->pixel = 0;
	// while (1)
	//{
		// inicializa a camera

		// initializa raydir e delta

		// inicializa distancia para lado

		// calcula o DDA

		// inicializa perpendicular

		// calcula raycasting

		// game->engine->dda->pixel++;
	//}
	//mlx_put_image_to_window(game->engine->mlx, game->engine->window, game->engine->img, 0, 0);
	
	return (0);
}