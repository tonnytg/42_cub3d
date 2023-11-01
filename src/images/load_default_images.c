/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_default_images.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:42:48 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/28 11:48:08 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	load_default_images(t_game *game)
{
	game->images->wall_2d_path = ft_strdup("./assets/sprites/wall_2d.xpm");
	game->images->wall_no.path = ft_strdup("./assets/sprites/wall_no.xpm");
	game->images->wall_so.path = ft_strdup("./assets/sprites/wall_so.xpm");
	game->images->wall_we.path = ft_strdup("./assets/sprites/wall_we.xpm");
	game->images->wall_ea.path = ft_strdup("./assets/sprites/wall_ea.xpm");
	return (0);
}
