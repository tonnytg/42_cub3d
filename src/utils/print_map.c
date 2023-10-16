/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:11:20 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/15 23:13:19 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	print_map_prompt(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	printf("lines: %d\n", game->map->lines);
	printf("columns: %d\n", game->map->columns);
	while (i < game->map->lines)
	{
		j = 0;
		while (j < game->map->columns)
		{
			printf("%c", game->map->grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
