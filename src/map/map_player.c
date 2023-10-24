/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:38:45 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/24 14:38:48 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

double	get_player_angle(char *player_position)
{
	if (player_position[0] == 'N')
		return (270);
	else if (player_position[0] == 'S')
		return (90);
	else if (player_position[0] == 'E')
		return (0);
	else if (player_position[0] == 'W')
		return (180);
	return (0);
}

int	discover_player_position(t_game *game)
{
	int		index;
	int		jndex;
	char	*player_position;

	index = 0;
	while (game->map->grid[index])
	{
		jndex = 0;
		while (game->map->grid[index][jndex])
		{
			if (ft_strchr("NSEW", game->map->grid[index][jndex]))
			{			
				player_position = ft_calloc(2, 1);
				player_position[0] = game->map->grid[index][jndex];
				game->player->angle = get_player_angle(player_position);
				game->player->x = jndex * TILE_SIZE;
				game->player->y = index * TILE_SIZE;
				free(player_position);
				return (1);
			}
			jndex++;
		}
		index++;
	}
	return (0);
}
