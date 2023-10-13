/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:53:48 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/13 04:57:13 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void print_map(t_game *game)
{
	printf("print map\n");
    for (int i = 0; i < game->map->lines; i++)
    {
        for (int j = 0; j < game->map->columns; j++)
        {
            printf("%c", game->map->grid[i][j]); // Imprime o caractere na posição (i, j)
        }
        printf("\n"); // Muda para a próxima linha do mapa
    }
	printf("end print map\n");
}

void	put_image(t_game *game, int *image, int x, int y)
{
	mlx_put_image_to_window(game->engine->mlx, game->engine->window, image, x * MAP_SIZE, y * MAP_SIZE);
}

void	put_player1(t_game *game, int x, int y)
{
	put_image(game, game->images->player, x, y);
	game->player->x = x;
	game->player->y = y;
}

void	put_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->engine->mlx,
		game->engine->window,
		game->images->player,
		x * PLAYER_SIZE,
		y * PLAYER_SIZE);
	game->player->x = x;
	game->player->y = y;
}


int	load_images(t_game *game)
{
	game->images->wall = mlx_xpm_file_to_image(game->engine->mlx, "textures/wall.xpm",
											   &game->images->x, &game->images->y);
	game->images->collectible = mlx_xpm_file_to_image(game->engine->mlx,
													  "textures/collectible.xpm", &game->images->x, &game->images->y);
	game->images->exit = mlx_xpm_file_to_image(game->engine->mlx,
											   "textures/exit.xpm",
											   &game->images->x, &game->images->y);
	game->images->player = mlx_xpm_file_to_image(game->engine->mlx,
												 "textures/player.xpm",
												 &game->images->x, &game->images->y);
	if (!game->images->wall
		|| !game->images->collectible
		|| !game->images->exit
		|| !game->images->player)
		return (1);
	return (0);
}

int	build_map(t_game *game)
{
	int	column;
	int	line;

	line = 0;
	while (line < game->map->lines)
	{
		column = 0;
		while (column < game->map->columns)
		{
			if (game->map->grid[line][column] == '1')
				put_image(game, game->images->wall, column, line);
			if (game->map->grid[line][column] == 'C')
				put_image(game, game->images->collectible, column, line);
			if (game->map->grid[line][column] == 'E')
				put_image(game, game->images->exit, column, line);
			if (game->map->grid[line][column] == 'P')
				put_player(game, column, line);
			column++;
		}
		line++;
	}
	return (0);
}

t_game	*start_game(t_game *game)
{
	if (game == NULL)
		return (NULL);
	print_map(game);
	game->engine->width = WIDTH;
	game->engine->height = HEIGHT;
	game->engine->mlx = mlx_init();
	if (!game->engine->mlx)
		return (NULL);
	game->engine->window = mlx_new_window(game->engine->mlx, game->engine->width, game->engine->height, "cub3D");
	// load_images(game);
	// build_map(game);
	// put_player(game, 10, 10);
	mlx_hook(game->engine->window, 17, 0, (void *)exit_game, game);
	mlx_hook(game->engine->window, 2, 1L << 0, key_press, game);
	mlx_loop(game->engine->mlx);
	return (game);
}
