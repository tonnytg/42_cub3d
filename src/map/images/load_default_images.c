/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_default_images.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:42:48 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/22 16:42:49 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	load_default_images(t_game *game)
{
	game->images->wall_no_path = ft_strdup("./assets/sprites/wall_no.xpm");
	game->images->wall_so_path = ft_strdup("./assets/sprites/wall_so.xpm");
	game->images->wall_we_path = ft_strdup("./assets/sprites/wall_we.xpm");
	game->images->wall_ea_path = ft_strdup("./assets/sprites/wall_ea.xpm");
	return (0);
}