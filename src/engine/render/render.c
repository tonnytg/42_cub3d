/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:29:54 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/28 16:31:58 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

// void	draw_circle(t_game *game, int x, int y, int r, int color)
// {
// 	int	i;
// 	int	j;
// 	for (i = x - r; i < x + r; i++)
// 	{
// 		for (j = y - r; j < y + r; j++)
// 		{
// 			if ((i - x) * (i - x) + (j - y) * (j - y) < r * r)
// 				mlx_pixel_put(
// 					game->mlx, game->window, i, j, color);
// 		}
// 	}
// }

// void	draw_line(t_game *game, int x0, int y0, int x1, int y1, int color)
// {
// 	int	dx = abs(x1 - x0);
// 	int	dy = abs(y1 - y0);
// 	int	sx = x0 < x1 ? 1 : - 1;
// 	int	sy = y0 < y1 ? 1 : - 1;
// 	int	err = (dx > dy ? dx : - dy) / 2;
// 	int	e2;

// 	while (1)
// 	{
// 		mlx_pixel_put(game->mlx, game->window, x0, y0, color);
// 		if (x0 == x1 && y0 == y1)
// 			break ;
// 		e2 = err;
// 		if (e2 > -dx)
// 		{
// 			err -= dy;
// 			x0 += sx;
// 		}
// 		if (e2 < dy)
// 		{
// 			err += dx;
// 			y0 += sy;
// 		}
// 	}
// }

// int	render_game(t_game *game)
// {
// 	int	end_x;
// 	int	end_y;
// 	int	fov_id;

// 	fov_id = 0;
// 	draw_background(game);
// 	draw_circle(game, game->player.x, game->player.y, PLAYER_SIZE, 0xFFFFFF);
// 	end_x = game->player.x + 6 * cos(game->player.angle * (M_PI / 180.0));
// 	end_y = game->player.y + 6 * sin(game->player.angle * (M_PI / 180.0));
// 	draw_line(game, game->player.x, game->player.y, end_x, end_y, 0xFF0000);
// 	put_player(game);
// 	build_map(game);
// 	calc_line_fov(game);
// 	while (fov_id < FOV)
// 	{
// 		calc_fov_line_distance(game, fov_id);
// 		draw_box(game, fov_id, game->player.line[fov_id].len / 3);
// 		fov_id++;
// 	}
// 	return (0);
// }