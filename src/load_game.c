/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:55:00 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/08 05:46:28 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
#include <fcntl.h>

int	read_map(t_game *game)
{
	char	buffer[1024];
	ssize_t	bytes_read;

	while ((bytes_read = read(game->map->fd, buffer, sizeof(buffer))) > 0)
	{
        // TODO: Realizar a leitura do arquivo
		// e salvar em uma estrutura que faça sentido.
    }	
	return (0);
}

t_game	*load_game(t_game *game, int argc, char **argv)
{
	printf("load game %d %s - game: %p\n", argc, argv[0], game);
	game->map->fd = open(argv[1], O_RDONLY);
	if (game->map->fd < 0)
	{
		printf("ERROR: can't open file map!");
		return (NULL);	
	}
	if (read_map(game))
	{
		printf("ERROR: can't read map inside file or invalid content!\n");
		return (NULL);
	}
	close(game->map->fd);
	return (game);
}
