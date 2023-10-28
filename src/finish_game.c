/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:54:42 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/28 10:22:31 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->images->wall_no);
	mlx_destroy_image(game->mlx, game->images->wall_so);
	mlx_destroy_image(game->mlx, game->images->wall_we);
	mlx_destroy_image(game->mlx, game->images->wall_ea);
	mlx_destroy_image(game->mlx, game->floor.img);
	mlx_destroy_image(game->mlx, game->sky.img);
}

void	clean_images_path(t_game *game)
{
	free(game->images->wall_no_path);
	free(game->images->wall_so_path);
	free(game->images->wall_we_path);
	free(game->images->wall_ea_path);
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
	if (game->player)
		free(game->player);
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
