/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:53:48 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/11 19:02:26 by antthoma         ###   ########.fr       */
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
	game->engine->window = mlx_new_window(game->engine->mlx,
			game->engine->width,
			game->engine->height,
			"cub3D");
	mlx_hook(game->engine->window, 2, 1L << 0, key_press, game);
	mlx_loop(game->engine->mlx);
	return (game);
}
