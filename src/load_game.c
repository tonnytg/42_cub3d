/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:55:00 by antthoma          #+#    #+#             */
/*   Updated: 2023/11/01 09:05:03 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	init_game_struct(t_game *game)
{
	game->images = ft_calloc(1, sizeof(t_images));
	load_default_colors(game);
	load_default_images(game);
	game->map = ft_calloc(1, sizeof(t_map));
	if (game->map == NULL)
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
	if (invalid_grid(game->map->grid))
	{
		printf("Error\nInvalid config file\n");
		return (NULL);
	}
	close(game->map->fd);
	return (game);
}
