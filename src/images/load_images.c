/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:45:12 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/31 17:21:13 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

// converte a imagem já salva dentro do mlx em um array de pixels
int	load_address_pixel_img(t_game *game)
{
	game->images->wall_no.addr = mlx_get_data_addr(game->images->wall_no.img,
			&game->images->wall_no.bpp, &game->images->wall_no.len,
			&game->images->wall_no.endian
			);
	game->images->wall_so.addr = mlx_get_data_addr(game->images->wall_so.img,
			&game->images->wall_so.bpp, &game->images->wall_so.len,
			&game->images->wall_so.endian
			);
	game->images->wall_ea.addr = mlx_get_data_addr(game->images->wall_ea.img,
			&game->images->wall_ea.bpp, &game->images->wall_ea.len,
			&game->images->wall_ea.endian
			);
	game->images->wall_we.addr = mlx_get_data_addr(game->images->wall_we.img,
			&game->images->wall_we.bpp, &game->images->wall_we.len,
			&game->images->wall_we.endian
			);
	return (0);
}

// carrega o arquivo em imagem e salva na struct
int	load_images(t_game *game)
{
	game->images->wall_2d = mlx_xpm_file_to_image(game->mlx,
			game->images->wall_2d_path,
			&game->images->width, &game->images->height);
	game->images->wall_no.img = mlx_xpm_file_to_image(game->mlx,
			game->images->wall_no.path,
			&game->images->width, &game->images->height);
	game->images->wall_so.img = mlx_xpm_file_to_image(game->mlx,
			game->images->wall_so.path,
			&game->images->width, &game->images->height);
	game->images->wall_we.img = mlx_xpm_file_to_image(game->mlx,
			game->images->wall_we.path,
			&game->images->width, &game->images->height);
	game->images->wall_ea.img = mlx_xpm_file_to_image(game->mlx,
			game->images->wall_ea.path,
			&game->images->width, &game->images->height);
	if (!game->images->wall_no.img
		|| !game->images->wall_so.img
		|| !game->images->wall_we.img
		|| !game->images->wall_ea.img)
	{
		printf("Error\narquivo de textura não encontrado\n");
		return (1);
	}
	load_address_pixel_img(game);
	return (0);
}
