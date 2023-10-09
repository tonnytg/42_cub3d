/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 00:12:15 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/09 15:03:16 by lbiasuz          ###   ########.fr       */
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
	printf("file map: %s\n", argv[1]);
	game->map->fd = open(argv[1], O_RDONLY);
	if (game->map->fd < 0)
	{
		printf("ERROR: can't open file map!");
		return (1);	
	}
	return (0);
}
