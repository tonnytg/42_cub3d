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

// converte a imagem já salva dentro do mlx em um array de pixels
int load_address_pixel_img(t_game *game)
{
	game->images->wall_no_addr = mlx_get_data_addr(game->images->wall_no,
		&game->images->wall_no_bpp, &game->images->wall_no_line_len,
		&game->images->wall_no_endian
	);
	game->images->wall_so_addr = mlx_get_data_addr(game->images->wall_so,
		&game->images->wall_so_bpp,&game->images->wall_so_line_len,
		&game->images->wall_so_endian
	);
	game->images->wall_ea_addr = mlx_get_data_addr(game->images->wall_ea,
		&game->images->wall_ea_bpp,&game->images->wall_ea_line_len,
		&game->images->wall_ea_endian
	);
	game->images->wall_we_addr = mlx_get_data_addr(game->images->wall_we,
		&game->images->wall_we_bpp,&game->images->wall_we_line_len,
		&game->images->wall_we_endian
	);
	return (0);
}

// carrega o arquivo em imagem e salva na struct
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
	load_address_pixel_img(game);
	return (0);
}
