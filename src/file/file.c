/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:12:15 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/13 04:32:54 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	open_file(t_game *game, char **argv)
{
	game->map->fd = open(argv[1], O_RDONLY);
	if (game->map->fd < 0)
	{
		printf("Error\ncan't open file map!");
		return (1);
	}
	return (0);
}