/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:38:30 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/13 05:25:16 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	exit_game(t_game *game)
{
	// imagens precisam ser deletadas antes do mlx
	mlx_destroy_image(game->engine->mlx, game->images->wall);
	mlx_destroy_image(game->engine->mlx, game->images->collectible);
	mlx_destroy_image(game->engine->mlx, game->images->exit);
	mlx_destroy_image(game->engine->mlx, game->images->player);	
	mlx_destroy_window(game->engine->mlx, game->engine->window);
	mlx_destroy_display(game->engine->mlx);
	if (game->engine->mlx)
		free(game->engine->mlx);
	clean_struct(game);
	exit (0);
}
