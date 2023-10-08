/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:12:15 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/08 05:07:16 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_bool	load_map(char *map_path, t_strc *strc)
{
	int	int_path;

	int_path = open(map_path, O_RDONLY);
	if (int_path < 0)
		exit_map_error(&strc->map, "Cannot open the map file", NULL, 0);
	map_data(&strc->map, &strc->player, &int_path);
	return (TRUE);
}

int	open_file(game, argv)
{
	game->map->fd = open(argv[1], O_RDONLY);
}
