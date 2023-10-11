/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:12:15 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/09 23:49:54 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


int	open_file(t_game *game, char **argv)
{
	game->map->fd = open(argv[1], O_RDONLY);
	if (game->map->fd < 0)
	{
		printf("ERROR: can't open file map!");
		return (1);	
	}
	return (0);
}

int	is_config_line(char	*line)
{
	if (ft_strncmp(line[0], "NO ", 3)
		|| ft_strncmp(line[0], "SO ", 3)
		|| ft_strncmp(line[0], "WE ", 3)
		|| ft_strncmp(line[0], "AE ", 3)
		|| ft_strncmp(line[0], "F ", 2)
		|| ft_strncmp(line[0], "C ", 2))
		return (1);
	return (0);
}

int	parse_config_file(t_game *game)
{
	char	*line;

	line = get_next_line(game->map->fd);
	while (line)
	{
		if (!is_config_line(line) && line[0] != '\n')
			return parse_map_file(game, line);
		free(line);
		line = get_next_line(game->map->fd);
	}
	free(line);
	return (0);
}

int	parse_map_file(t_game *game, char *line)
{
	char	*full_map;

	full_map = "";
	while (line && line[0] != '\n')
	{
		full_map = ft_strjoin(full_map, line);
		free(line);
		line = get_next_line(game->map->fd);
	}
	game->map->grid = ft_split(full_map, '\n');
	if (full_map[0] != '\0')
		free(full_map);
	return (1);
}

int	normalize_map_size(t_game *game)
{
	int		index;
	int		biggest_size;
	char	*normalized_string;

	index = 0;
	biggest_size = 0;
	while (game->map->grid[index])
	{
		if (biggest_size < ft_strlen(game->map->grid[index]))
			biggest_size = ft_strlen(game->map->grid[index]);
		index++;
	}
	index--;
	while (index--)
	{
		if (ft_strlen(game->map->grid[index]) < biggest_size)
		{
			// TODO: não finalizado
			normalized_string = ft_strjoin()
		}
	}
	return (1);
}