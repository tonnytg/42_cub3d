/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:43:19 by lbiasuz           #+#    #+#             */
/*   Updated: 2023/10/13 15:37:13 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	arr_size(char	**grid)
{
	int	index;

	index = 0;
	while (grid[index])
		index++;
	return (index);
}
 
int	verify_valid_node(char **grid, int x, int y)
{
	if (!ft_strchr("01NESW", grid[y][x]))
		return (0);
	if (grid[y][x] != '1')
	{
		if (x == 0 || y == 0 || x == (int) ft_strlen(grid[y])
			|| y == arr_size(grid))
			return (0);
		if (!ft_strchr("01NESW", grid[y][x + 1])
		|| !ft_strchr("01NESW", grid[y][x - 1])
		|| !ft_strchr("01NESW", grid[y + 1][x])
		|| !ft_strchr("01NESW", grid[y - 1][x]))
			return (0);
	}
	return (1);
}

int	verify_grid(char **grid)
{
	int	x;
	int	y;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while(grid[y][x])
		{
			if (!verify_valid_node(grid, x, y))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
