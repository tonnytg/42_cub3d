/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:27:39 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/14 12:27:49 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	get_size_map(t_game *game)
{
	char	*line;

	line = get_next_line(game->map->fd);
	if (line == NULL)
		return (1);
	game->map->lines = 0;
	game->map->columns = 0;
	while (line != NULL)
	{
		game->map->lines++;
		count_columns(line, &game->map->columns);
		free(line);
		line = get_next_line(game->map->fd);
	}
	return (0);
}
