/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:54:42 by antthoma          #+#    #+#             */
/*   Updated: 2023/11/01 20:55:51 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	destroy_images(t_game *game)
{
	if (game->images->wall_2d)
		mlx_destroy_image(game->mlx, game->images->wall_2d);
	if (game->images->wall_no.img)
		mlx_destroy_image(game->mlx, game->images->wall_no.img);
	if (game->images->wall_so.img)
		mlx_destroy_image(game->mlx, game->images->wall_so.img);
	if (game->images->wall_we.img)
		mlx_destroy_image(game->mlx, game->images->wall_we.img);
	if (game->images->wall_ea.img)
		mlx_destroy_image(game->mlx, game->images->wall_ea.img);
	if (game->floor.img)
		mlx_destroy_image(game->mlx, game->floor.img);
	if (game->sky.img)
		mlx_destroy_image(game->mlx, game->sky.img);
	free(game->images->wall_2d_path);
	free(game->images->wall_no.path);
	free(game->images->wall_so.path);
	free(game->images->wall_we.path);
	free(game->images->wall_ea.path);
}

void	free_table(char **table)
{
	int	index;

	index = 0;
	while (table[index])
	{
		free(table[index]);
		index++;
	}
	free(table);
}

int	clean_struct(t_game *game)
{
	if (game->images)
		free(game->images);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map->grid)
		free_table(game->map->grid);
	free(game->map);
	if (game)
		free(game);
	return (0);
}

t_game	*finish_game(t_game *game)
{
	destroy_images(game);
	clean_struct(game);
	return (NULL);
}
