/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:54:42 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/28 13:10:45 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->images->wall_no.img);
	mlx_destroy_image(game->mlx, game->images->wall_so.img);
	mlx_destroy_image(game->mlx, game->images->wall_we.img);
	mlx_destroy_image(game->mlx, game->images->wall_ea.img);
	mlx_destroy_image(game->mlx, game->floor.img);
	mlx_destroy_image(game->mlx, game->sky.img);
}

void	clean_images_path(t_game *game)
{
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
	{
		clean_images_path(game);
		free(game->images);
	}
	free_table(game->map->grid);
	free(game->map);
	if (game)
		free(game);
	return (0);
}

t_game	*finish_game(t_game *game)
{
	clean_struct(game);
	return (NULL);
}
