/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_custom_images.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:42:29 by antthoma          #+#    #+#             */
/*   Updated: 2023/11/02 15:27:39 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	load_texture_north_wall(t_game *game, char *texture)
{
	free(game->images->wall_no.path);
	game->images->wall_no.path = ft_strdup(texture);
	game->map->count_custom_wall_no++;
	return (0);
}

int	load_texture_south_wall(t_game *game, char *texture)
{
	free(game->images->wall_so.path);
	game->images->wall_so.path = ft_strdup(texture);
	game->map->count_custom_wall_so++;
	return (0);
}

int	load_texture_west_wall(t_game *game, char *texture)
{
	free(game->images->wall_we.path);
	game->images->wall_we.path = ft_strdup(texture);
	game->map->count_custom_wall_we++;
	return (0);
}

int	load_texture_east_wall(t_game *game, char *texture)
{
	free(game->images->wall_ea.path);
	game->images->wall_ea.path = ft_strdup(texture);
	game->map->count_custom_wall_ea++;
	return (0);
}

int	load_custom_images(t_game *game, char *line, char *config)
{
	char	**custom_image;

	custom_image = ft_split(line, ' ');
	custom_image[1][ft_strlen(custom_image[1]) - 1] = 0;
	if (count_array(custom_image) != 2)
	{
		game->map->has_error++;
		free_array(custom_image);
		return (1);
	}
	if (ft_strncmp(custom_image[0], "NO", 2) == 0)
		load_texture_north_wall(game, custom_image[1]);
	else if (ft_strncmp(custom_image[0], "SO", 2) == 0)
		load_texture_south_wall(game, custom_image[1]);
	else if (ft_strncmp(custom_image[0], "WE", 2) == 0)
		load_texture_west_wall(game, custom_image[1]);
	else if (ft_strncmp(custom_image[0], "EA", 2) == 0)
		load_texture_east_wall(game, custom_image[1]);
	else
	{
		free_array(custom_image);
		return (1);
	}
	free_array(custom_image);
	return (0);
}
