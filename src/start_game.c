/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:53:48 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/13 13:39:50 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw_circle(t_game *game, int x_center, int y_center, int radius, int color)
{
	int x = radius;
	int y = 0;
	int p = 1 - radius;

	while (x >= y)
	{
		mlx_pixel_put(game->engine->mlx, game->engine->window, x_center + x, y_center + y, color);
		mlx_pixel_put(game->engine->mlx, game->engine->window, x_center - x, y_center + y, color);
		mlx_pixel_put(game->engine->mlx, game->engine->window, x_center + x, y_center - y, color);
		mlx_pixel_put(game->engine->mlx, game->engine->window, x_center - x, y_center - y, color);
		mlx_pixel_put(game->engine->mlx, game->engine->window, x_center + y, y_center + x, color);
		mlx_pixel_put(game->engine->mlx, game->engine->window, x_center - y, y_center + x, color);
		mlx_pixel_put(game->engine->mlx, game->engine->window, x_center + y, y_center - x, color);
		mlx_pixel_put(game->engine->mlx, game->engine->window, x_center - y, y_center - x, color);

		y++;

		if (p <= 0)
			p = p + 2 * y + 1;
		else
		{
			x--;
			p = p + 2 * y - 2 * x + 1;
		}
	}
}

void	draw_line(t_game *game, int x0, int y0, int x1, int y1, int color)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2;
	int e2;

	while (1)
	{
		mlx_pixel_put(game->engine->mlx, game->engine->window, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}


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

void	put_player1old(t_game *game, int x, int y)
{
	put_image(game, game->images->player, x, y);
	game->player->x = x;
	game->player->y = y;
}

void	put_player22(t_game *game, int x, int y)
{
	int color = 0x00FF00; // Cor verde para o jogador
	int radius = PLAYER_SIZE / 2; // Raio da bolinha

	draw_circle(game, x * MAP_SIZE + radius, y * MAP_SIZE + radius, radius, color);

	game->player->x = x;
	game->player->y = y;
}

void	put_player(t_game *game, int x, int y)
{
	int color = 0x00FF00; // Cor verde para o jogador
	int radius = PLAYER_SIZE / 2; // Raio da bolinha
	int line_length = radius + 10; // Comprimento da linha indicadora

	// Desenha o círculo do jogador
	draw_circle(game, x * MAP_SIZE + radius, y * MAP_SIZE + radius, radius, color);

	// Desenha a linha indicadora com base no ângulo
	int end_x = x * MAP_SIZE + radius + line_length * cos(game->player->angle);
	int end_y = y * MAP_SIZE + radius - line_length * sin(game->player->angle); // '-' porque o eixo y é invertido na tela

	draw_line(game, 
			  x * MAP_SIZE + radius, 
			  y * MAP_SIZE + radius, 
			  end_x, 
			  end_y, 
			  color);

	game->player->x = x;
	game->player->y = y;
}

void	put_player1(t_game *game, int x, int y)
{
	int color = 0x00FF00; // Cor verde para o jogador
	int radius = PLAYER_SIZE / 2; // Raio da bolinha
	int line_length = radius + 10; // Comprimento da linha indicadora

	// Desenha o círculo do jogador
	draw_circle(game, x * MAP_SIZE + radius, y * MAP_SIZE + radius, radius, color);

	// Desenha a linha indicadora
	// Aqui, estamos desenhando a linha para cima. Modifique conforme a direção desejada.
	draw_line(game, 
			  x * MAP_SIZE + radius, 
			  y * MAP_SIZE + radius, 
			  x * MAP_SIZE + radius, 
			  y * MAP_SIZE + radius - line_length, 
			  color);

	game->player->x = x;
	game->player->y = y;
}

void	put_playerold2(t_game *game, int x, int y)
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
												&game->images->width, &game->images->height);
	game->images->collectible = mlx_xpm_file_to_image(game->engine->mlx,
												"textures/collectible.xpm",
												&game->images->width, &game->images->height);
	game->images->exit = mlx_xpm_file_to_image(game->engine->mlx,
											   "textures/exit.xpm",
											   &game->images->width, &game->images->height);
	game->images->player = mlx_xpm_file_to_image(game->engine->mlx,
												"textures/player.xpm",
												&game->images->width, &game->images->height);
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
	load_images(game);
	build_map(game);
	put_player(game, game->player->x, game->player->y);
	mlx_hook(game->engine->window, 17, 0, (void *)exit_game, game);
	mlx_hook(game->engine->window, 2, 1L << 0, key_press, game);
	mlx_loop(game->engine->mlx);
	return (game);
}
