/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:55:00 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/15 04:16:13 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <fcntl.h>

int	init_game_struct(t_game *game)
{
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
	init_game_struct(game);
	if (open_file(game, argv))
	{
		printf("ERROR: can't open file map!");
		return (NULL);	
	}
	if (read_map(game))
	{
		printf("ERROR: can't read map inside file or invalid content!\n");
		return (NULL);
	}
	if (!verify_grid(game->map->grid))
		printf("Grid invalido \n");
	int index = 0;
	while (game->map->grid[index])
	{
		printf("%s|\n", game->map->grid[index]);
		index++;
	}
	close(game->map->fd);
	return (game);
}
