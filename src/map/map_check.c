/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:43:19 by lbiasuz           #+#    #+#             */
/*   Updated: 2023/11/02 13:30:48 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	arr_size(char	**grid)
{
	int	index;

	index = 0;
	while (grid[index])
		index++;
	return (index);
}

// static int	invalid_node_1(char **grid, int x, int y)
// {
// 	static int	players;

// 	if (x == 0 && y == 0)
// 		players = 0;
// 	if (ft_strchr("01NESW ", grid[y][x]) == 0)
// 		return (1);
// 	if (grid[y][x] != '1' && grid[y][x] != ' ')
// 	{
// 		if (x == 0 || y == 0 || x == (int) ft_strlen(grid[y])
// 			|| y == arr_size(grid))
// 			return (1);
// 		if (!ft_strchr("01NESW", grid[y][x + 1])
// 		|| !ft_strchr("01NESW", grid[y][x - 1])
// 		|| !ft_strchr("01NESW", grid[y + 1][x])
// 		|| !ft_strchr("01NESW", grid[y - 1][x]))
// 			return (1);
// 	}
// 	if (ft_strchr("NESW", grid[y][x]))
// 		players++;
// 	if (players != 1)
// 		return (1);
// 	return (0);
// }

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

int	invalid_grid(char **grid)
{
	int	x;
	int	y;
	int	players;

	players = 0;
	y = 0;
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
