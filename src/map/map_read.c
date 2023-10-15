/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:38:54 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/15 22:20:17 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	is_config_line(char	*line)
{
	if (!ft_strncmp(line, "NO ", 3)
		|| !ft_strncmp(line, "SO ", 3)
		|| !ft_strncmp(line, "WE ", 3)
		|| !ft_strncmp(line, "EA ", 3)
		|| !ft_strncmp(line, "F ", 2)
		|| !ft_strncmp(line, "C ", 2))
		return (1);
	return (0);
}

int	find_biggest_row_size(char **grid)
{
	int		index;
	size_t	biggest_size;

	index = 0;
	biggest_size = 0;
	while (grid[index])
	{
		if (biggest_size < ft_strlen(grid[index]))
			biggest_size = ft_strlen(grid[index]);
		index++;
	}
	return (biggest_size);
}

int	normalize_map_size(char **grid)
{
	int		index;
	size_t	biggest_size;
	char	*filler_string;
	char	*normalized_string;

	index = 0;
	biggest_size = find_biggest_row_size(grid);
	while (grid[index])
	{
		if (ft_strlen(grid[index]) < biggest_size)
		{
			filler_string = ft_calloc(
					biggest_size - ft_strlen(grid[index]) + 1, 1);
			ft_memset(
				filler_string, ' ', biggest_size - ft_strlen(grid[index]));
			normalized_string = ft_strjoin(grid[index], filler_string);
			free(filler_string);
			free(grid[index]);
			grid[index] = normalized_string;
		}
		index++;
	}
	return (1);
}

int	parse_map_file(t_game *game, char *line)
{
	char	*full_map;
	char	*temp;

	full_map = "";
	while (line)
	{
		temp = full_map;
		full_map = ft_strjoin(full_map, line);
		free(line);
		line = get_next_line(game->map->fd);
		if (temp[0] != 0)
			free(temp);
	}
	game->map->grid = ft_split(full_map, '\n');
	if (full_map[0] != 0)
		free(full_map);
	normalize_map_size(game->map->grid);
	return (0);
}

int	read_map(t_game *game)
{
	char	*line;

	line = get_next_line(game->map->fd);
	while (line)
	{
		if (!is_config_line(line) && line[0] != '\n')
			return (parse_map_file(game, line));
		free(line);
		line = get_next_line(game->map->fd);
	}
	free(line);
	return (0);
}
