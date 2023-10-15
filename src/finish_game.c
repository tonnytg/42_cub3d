/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:54:42 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/15 21:05:25 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	free_table(char **table)
{
	int	index;

	index = 0;
	while (table[index])
	{
		free(table[index]);
		index++;
	}
	free(table);
}

t_game	*clean_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->lines)
	{
		if (game->map->grid[i])
			free(game->map->grid[i]);
		i++;
	}
	return (game);
}

int	clean_struct(t_game *game)
{
	if (game->images)
		free(game->images);
	if (game->player)
	{
		if (game->player->circle)
			free(game->player->circle);
		if (game->player->line)
			free(game->player->line);
		free(game->player);
	}
	free_table(game->map->grid);
	if (game->map)
	{
		clean_map(game);
		free(game->map);
	}
	if (game->engine)
		free(game->engine);
	if (game)
		free(game);
	return (0);
}

t_game	*finish_game(t_game *game)
{
	
	clean_struct(game);
	return (NULL);
}
