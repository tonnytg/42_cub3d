/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 01:22:26 by lbiasuz           #+#    #+#             */
/*   Updated: 2023/10/28 16:25:51 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw_circle(t_game *game, int x, int y, int r, int color)
{
	int	i;
	int	j;
	for (i = x - r; i < x + r; i++)
	{
		for (j = y - r; j < y + r; j++)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) < r * r)
				mlx_pixel_put(
					game->mlx, game->window, i, j, color);
		}
	}
}

void	draw_line(t_game *game, int x0, int y0, int x1, int y1, int color)
{
	int	dx = abs(x1 - x0);
	int	dy = abs(y1 - y0);
	int	sx = x0 < x1 ? 1 : - 1;
	int	sy = y0 < y1 ? 1 : - 1;
	int	err = (dx > dy ? dx : - dy) / 2;
	int	e2;

	while (1)
	{
		mlx_pixel_put(game->mlx, game->window, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	draw_box(t_game *game, int fov_id, int len, int side)
{
	int		y;
	int		corrected_height;
	int		start_y;
	int		texture_x;
	int		texture_y;
	char	*texture_addr;
	int		texture_pixel;

	texture_addr = 0;
	if (side)
		texture_addr = game->images->wall_no.addr;
	else
		texture_addr = game->images->wall_so.addr;
	// else if (game->player.line[fov_id].wall_side == 'E')
	// 	texture_addr = game->images->wall_ea.addr;
	// else if (game->player.line[fov_id].wall_side == 'W')
	// 	texture_addr = game->images->wall_we.addr;
	corrected_height = HEIGHT;
	if (len != 0)
		corrected_height = HEIGHT / len;
	start_y = (HEIGHT / 2) - (corrected_height / 2);
	y = start_y;
	while (y < (start_y + corrected_height))
	{
		texture_x = (fov_id % game->images->width);
		texture_y = ((y - start_y) * game->images->height) \
				/ corrected_height;
		texture_pixel = *(int *)(texture_addr
				+ (texture_y * game->images->wall_no.len)
				+ (texture_x * (game->images->wall_no.bpp / 8)));
		mlx_pixel_put(
			game->mlx, game->window, fov_id, y, texture_pixel);
		y++;
	}
}

double	rad(double d)
{
	return (d + M_PI / 180.0);
}

int	render_game(t_game *game)
{
	put_player(game);
	
	t_player plyr = game->player;

	draw_background(game);

	draw_circle(game, plyr.x * TILE_SIZE, plyr.y * TILE_SIZE, PLAYER_SIZE, 0xFFFFFF);  // Player como um círculo branco
		
	// Direção do player
	int line_length = 6;  // Ou qualquer comprimento desejado para a linha
	int end_x = plyr.x * TILE_SIZE + line_length * cos(plyr.angle * (M_PI / 180.0));
	int end_y = plyr.y * TILE_SIZE + line_length * sin(plyr.angle * (M_PI / 180.0));
	draw_line(game, plyr.x * TILE_SIZE, plyr.y * TILE_SIZE, end_x , end_y , 0xFF0000);  // Linha em vermelho

	build_map(game);

	double posX = plyr.x, posY = plyr.y;  //x and y start position
	double dirX = cos(rad(plyr.angle)), dirY = sin(rad(plyr.angle)); //initial direction vector
	double planeX = 0.0, planeY = 0.66;

	double fov_id = 0;

	while (fov_id < WIDTH)
	{
		double cameraX = 2 * fov_id / (double) WIDTH - 1; //x-coordinate in camera space
		double rayDirX = dirX + planeX*cameraX;
		double rayDirY = dirY + planeY*cameraX;
		int mapX = (int) (posX);
		int mapY = (int) (posY);
		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		double sideDistX;
		double sideDistY;
		int stepX;
		int stepY;
		int hit = 0;
		int side;
		double perpWallDist;

		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}

		while (hit == 0)
		{
		//jump to next map square, either in x-direction, or in y-direction
		if(sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
		}
		//Check if ray has hit a wall
		printf("%d %d \n", mapY, mapX);
		if(game->map->grid[mapY][mapX] == '1') hit = 1;
		}
		
		if(side == 0) perpWallDist = (sideDistX - deltaDistX);
		else	perpWallDist = (sideDistY - deltaDistY);


		draw_box(game, fov_id, perpWallDist, side);

		fov_id++;
	}

	return (0);
}

// void	calc_line_fov(t_game *game)
// {
// 	int			fov_id;
// 	double		start_angle;
// 	double		angle_increment;
// 	t_fov_line	*l;

// 	fov_id = 0;
// 	start_angle = game->player.angle * (M_PI / 180.0) - 
// 		(FOV / 2) * (M_PI / 180.0);
// 	angle_increment = (double) FOV / FOV * (M_PI / 180.0);
// 	while (fov_id < FOV)
// 	{
// 		l = &game->player.line[fov_id];
// 		l->angle = start_angle;
// 		l->end.x = l->beg.x + FOV_LENGTH * cos(start_angle);
// 		l->end.y = l->beg.y + FOV_LENGTH * sin(start_angle);
// 		calc_fov_line_distance(game, fov_id);
// 		start_angle += angle_increment;
// 		fov_id++;
// 	}
// }

// void	set_value_to_draw_line(t_fov_line *l)
// {
// 	l->dist.x = fabs(l->end.x - l->beg.x);
// 	l->dist.y = fabs(l->end.y - l->beg.y);
// 	if (l->beg.x < l->end.x)
// 		l->step.x = 1;
// 	else
// 		l->step.x = -1;
// 	if (l->beg.y < l->end.y)
// 		l->step.y = 1;
// 	else
// 		l->step.y = -1;
// 	if (l->dist.x > l->dist.y)
// 		l->err = l->dist.x / 2;
// 	else
// 		l->err = -l->dist.y / 2;
// }

// // calcula a distancia do raio até colidir com alguma parede
// void	calc_fov_line_distance(t_game *game, int fov_id)
// {
// 	t_fov_line	*l;
// 	int			map_x;
// 	int			map_y;

// 	l = &game->player.line[fov_id];
// 	set_value_to_draw_line(l);
// 	while (l->beg.x != l->end.x || l->beg.y != l->end.y)
// 	{
// 		l->len++;
// 		if (l->err > -l->dist.x)
// 		{
// 			l->err -= l->dist.y;
// 			l->beg.x += l->step.x;
// 			l->wall_side = (l->step.y > 0) ? 'E' : 'W';
// 		}
// 		if (l->err < l->dist.y)
// 		{
// 			l->err += l->dist.x;
// 			l->beg.y += l->step.y;
// 			l->wall_side = (l->step.x > 0) ? 'S' : 'N';
// 		}
// 		map_x = l->beg.x / TILE_SIZE;
// 		map_y = l->beg.y / TILE_SIZE;
// 		if (map_x >= 0 && map_x < game->map->columns && map_y >= 0
// 			&& map_y < game->map->lines && game->map->grid[map_y][map_x] == '1')
// 				break ;
// 	}
// }
