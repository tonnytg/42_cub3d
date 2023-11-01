/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:53:48 by antthoma          #+#    #+#             */
/*   Updated: 2023/11/01 22:22:15 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	expose_hook(t_game *game)
{
	render_game(game);
	return (0);
}

t_game	*start_game(t_game *game)
{
	if (game == NULL)
		return (NULL);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (NULL);
	if (load_images(game))
		return (NULL);
	game->window = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	render_game(game);
	mlx_expose_hook(game->window, expose_hook, game);
	mlx_hook(game->window, 17, 0, (void *)exit_game, game);
	mlx_hook(game->window, 2, 1L << 0, key_press, game);
	mlx_loop(game->mlx);
	return (game);
}
