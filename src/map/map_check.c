/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:43:19 by lbiasuz           #+#    #+#             */
/*   Updated: 2023/11/02 14:46:33 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	count_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		i++;
	}
	return (i);
}

int	check_duplicate_values(t_game *game)
{
	int	duplicate_values;

	duplicate_values = 0;
	if ((game->map->count_custom_wall_no > 1)
		|| (game->map->count_custom_wall_so > 1)
		|| (game->map->count_custom_wall_we > 1)
		|| (game->map->count_custom_wall_ea > 1)
		|| (game->map->count_custom_color_f > 1)
		|| (game->map->count_custom_color_c > 1))
		duplicate_values++;
	if (duplicate_values != 0)
	{
		printf("Error\nconfig file with duplicate values\n");
		return (1);
	}
	return (0);
}

static int	arr_size(char	**grid)
{
	int	index;

	index = 0;
	while (grid[index])
		index++;
	return (index);
}

static int	invalid_node(char **grid, int x, int y, int *players)
{
	if (ft_strchr("01NESW ", grid[y][x]) == 0)
		return (1);
	if (grid[y][x] != '1' && grid[y][x] != ' ')
	{
		if (x == 0 || y == 0 || x == (int) ft_strlen(grid[y])
			|| y == arr_size(grid))
			return (1);
		if (!ft_strchr("01NESW", grid[y][x + 1])
		|| !ft_strchr("01NESW", grid[y][x - 1])
		|| !ft_strchr("01NESW", grid[y + 1][x])
		|| !ft_strchr("01NESW", grid[y - 1][x]))
			return (1);
	}
	if (ft_strchr("NESW", grid[y][x]))
		*players = *players + 1;
	return (0);
}

int	invalid_grid(t_game *game, char **grid)
{
	int	x;
	int	y;
	int	players;

	players = 0;
	y = 0;
	if (check_duplicate_values(game))
		return (1);
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (invalid_node(grid, x, y, &players))
				return (1);
			x++;
		}
		y++;
	}
	if (players != 1)
	{
		printf("Error\nwrong player number:%d\n", players);
		return (1);
	}
	return (0);
}
