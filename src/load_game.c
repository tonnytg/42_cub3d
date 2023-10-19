/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:55:00 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/18 20:26:21 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	init_game_struct(t_game *game)
{
	game->images = ft_calloc(1, sizeof(t_images));
	game->player = ft_calloc(1, sizeof(t_player));
	game->map = ft_calloc(1, sizeof(t_map));
	if (game->map == NULL)
		return (1);
	game->engine = ft_calloc(1, sizeof(t_engine));
	if (game->engine == NULL)
		return (1);
	return (0);
}

t_game	*load_game(t_game *game, char **argv)
{
	if (game == NULL)
	{
		printf("Error\nNot enough resources available to allocate memory.");
		return (NULL);
	}
	init_game_struct(game);
	if (open_file(game, argv))
		return (NULL);
	if (read_map(game))
	{
		printf("Error\ncan't read map inside file or invalid content!\n");
		return (NULL);
	}
	if (!verify_grid(game->map->grid))
		printf("Error\nInvalid Grid\n");
	close(game->map->fd);
	return (game);
}
