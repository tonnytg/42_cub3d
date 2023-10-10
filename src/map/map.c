/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:38:54 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/09 23:50:02 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int count_columns(char *str, int *columns)
{
	int	i;

	i = 0;
    while (str[i] != '\0')
	{
        i++;
    }
	if (*columns < i)
		*columns = i;
    return i;
}

int	get_size_map(t_game *game)
{
	char	buffer[1024];
	char	line[MAX_LINE_SIZE];
	size_t	line_size;
	ssize_t	bytes_read;
	ssize_t	i;
	int count_l;
	int count_c;

	count_l = 0;
	count_c = 0;
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
				line_size = 0;
				count_l++;
				count_columns(line, &count_c);
			}
            else
                line[line_size++] = buffer[i];		
			i++;
		}
		if (buffer[bytes_read - 1] == '\n')
			break ;
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
		count_l++;
		count_columns(line, &count_c);
	}
	game->map->lines = count_l;
	game->map->columns = count_c;
	return (0);
}

t_game	*create_map(t_game *game)
{
	int		i;

	i = 0;
    game->map->grid = (char **)malloc(game->map->lines * sizeof(char *));
	while (i < game->map->lines)
    {
        game->map->grid[i] = (char *)malloc(game->map->columns * sizeof(char));
		i++;
    }
    return	(game);
}

t_game *set_value_to_map(t_game *game, int line_number, char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		printf("value line[i]: %c", line[i]);
		game->map->grid[line_number][i] = line[i];
		i++;
	}
	printf("grid[%d]: %s\n", line_number, game->map->grid[line_number]);
	return (game);
}

int	read_map(t_game *game)
{
	char	buffer[1024];
	char	line[MAX_LINE_SIZE];
	size_t	line_size;
	ssize_t	bytes_read;
	ssize_t	i;
	int line_number;

	line_size = 0;
	line_number = 0;
	bytes_read = read(game->map->fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		i = 0;
		while (i < bytes_read)
		{
			if (buffer[i] == '\n' || buffer[i] == '\0')
			{
				line[line_size] = '\0';
				set_value_to_map(game, line_number, line);
				line_size = 0;
				line_number++;
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
		set_value_to_map(game, line_number + 1, line);
	}
	return (0);
}
