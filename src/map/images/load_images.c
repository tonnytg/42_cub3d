/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:45:12 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/22 16:45:12 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	load_images(t_game *game)
{
	game->images->wall_no = mlx_xpm_file_to_image(game->engine->mlx,
			game->images->wall_no_path,
			&game->images->width, &game->images->height);
	game->images->wall_so = mlx_xpm_file_to_image(game->engine->mlx,
			game->images->wall_so_path,
			&game->images->width, &game->images->height);
	game->images->wall_we = mlx_xpm_file_to_image(game->engine->mlx,
			game->images->wall_we_path,
			&game->images->width, &game->images->height);
	game->images->wall_ea = mlx_xpm_file_to_image(game->engine->mlx,
			game->images->wall_ea_path,
			&game->images->width, &game->images->height);
	if (!game->images->wall_no
		|| !game->images->wall_so
		|| !game->images->wall_we
		|| !game->images->wall_ea)
		return (1);
	return (0);
}
