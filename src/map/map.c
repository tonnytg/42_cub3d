/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:38:54 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/14 12:31:55 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	count_columns(char *str, int *columns)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	if (*columns < i)
		*columns = i;
	return (i);
}

t_game	*create_map(t_game *game)
{
	int	i;

	i = 0;
	game->map->grid = ft_calloc(game->map->lines + 1, sizeof(char *));
	while (i < game->map->lines)
	{
		game->map->grid[i] = ft_calloc(game->map->columns, sizeof(char));
		i++;
	}
	return (game);
}

t_game	*set_value_to_map(t_game *game, int line_number, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		game->map->grid[line_number][i] = line[i];
		i++;
	}
	return (game);
}

int	read_map(t_game *game)
{
	char	*line;
	int		line_number;

	line_number = 0;
	line = get_next_line(game->map->fd);
	if (line == NULL)
		return (1);
	while (line != NULL)
	{
		set_value_to_map(game, line_number, line);
		line_number++;
		free(line);
		line = get_next_line(game->map->fd);
	}
	if (line)
		free(line);
	return (0);
}
