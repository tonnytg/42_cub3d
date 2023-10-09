/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:38:54 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/09 20:32:44 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	read_map(t_game *game)
{
	char	buffer[1024];
	char	line[MAX_LINE_SIZE];
	size_t	line_size;
	ssize_t	bytes_read;
	ssize_t	i;

	line_size = 0;
	bytes_read = read(game->map->fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		i = 0;
		while (i < bytes_read)
		{
			if (buffer[i] == '\n' || buffer[i] == '\0')
			{
				line[line_size] = '\0';
				printf("%s\n", line);
				line_size = 0;
			}
			else
				line[line_size++] = buffer[i];
			i++;
		}
		if (buffer[bytes_read - 1] == '\n')
		{
			printf("end of line\n");
			break ;
		}
		bytes_read = read(game->map->fd, buffer, sizeof(buffer));
	}
	if (bytes_read == -1)
	{
		perror("Erro na leitura do arquivo");
		exit(1);
	}
	if (line_size > 0)
	{
		line[line_size] = '\0';
		printf("%s\n", line);
	}
	return (0);
}
