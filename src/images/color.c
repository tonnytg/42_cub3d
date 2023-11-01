/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:19:22 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/22 14:19:23 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	decode_rgb(int r, int g, int b)
{
	int	rgb;

	rgb = 0;
	if (r == 0 && b == 0 && g == 0)
		r = 1;
	if ((r > 255 || r < 0) || (b > 255 || b < 0) || (g > 255 || g < 0))
		return (0);
	rgb += (r & 0xFF) << 16;
	rgb += (g & 0xFF) << 8;
	rgb += (b & 0xFF);
	return (rgb);
}

int	load_custom_color(t_game *game, char *line, char *config)
{
	char	**content;
	char	**rgb;
	int		color;	

	content = ft_split(line, ' ');
	rgb = ft_split(content[1], ',');
	free(content[0]);
	free(content[1]);
	free(content);
	color = decode_rgb(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	if (ft_strcmp(config, "F") == 0)
		game->images->floor_color = color;
	if (ft_strcmp(config, "C") == 0)
		game->images->sky_color = color;
	free(rgb[0]);
	free(rgb[1]);
	free(rgb[2]);
	free(rgb);
	return (0);
}

int	load_default_colors(t_game *game)
{
	printf("Loading default colors\n");
	game->images->floor_color = DEFAULT_FLOOR_COLOR;
	game->images->sky_color = DEFAULT_SKY_COLOR;
	return (0);
}
