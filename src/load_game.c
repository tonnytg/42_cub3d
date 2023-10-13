/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:55:00 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/13 05:01:42 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	init_game_struct(t_game *game)
{
	// game->images = ft_calloc(1, sizeof(t_images));
	// game->player = ft_calloc(1, sizeof(t_player));
	
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
		return (NULL);
	init_game_struct(game);
	if (open_file(game, argv))
	{
		printf("Error\ncan't open file map!");
		return (NULL);
	}
	if (get_size_map(game))
	{
		printf("Error\ncan't read map inside file or invalid content!\n");
		return (NULL);
	}
	close(game->map->fd);
	if (open_file(game, argv))
	{
		printf("Error\ncan't open file map!");
		return (NULL);
	}
	printf("line: %d\n", game->map->lines);
	printf("columns: %d\n", game->map->columns);
	create_map(game);
	if (read_map(game))
	{
		printf("Error\ncan't read map inside file or invalid content!\n");
		return (NULL);
	}
	close(game->map->fd);
	return (game);
}
