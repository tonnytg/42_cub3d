/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:54:42 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/16 15:07:35 by lbiasuz          ###   ########.fr       */
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
		if (game->player->fov_line)
			free(game->player->fov_line);
		free(game->player);
	}
	free_table(game->map->grid);
	free(game->map);
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
