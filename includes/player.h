/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:16:27 by lbiasuz           #+#    #+#             */
/*   Updated: 2023/10/30 18:34:35 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define TURN_SPEED 5
# define MOVE_SPEED 0.5
# define PLAYER_SIZE 2
# define CIRCLE_COLOR 0xFFFFFF
# define LINE_COLOR 0xFF0000

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_inp
{
	int	x;
	int	y;
}	t_inp;

typedef struct s_fov_line
{
	t_point	pos;
	t_point	dir;
	t_point	ray;
	t_point	dist;
	t_point	side;
	t_point	step;
	t_point	map;
	t_point	plane;
	int		id;
	double	camera;
	double	len;
	char	wall_side;
}	t_fov_line;

typedef struct s_player
{
	t_fov_line	line;
	double		x;
	double		y;
	double		angle;
}	t_player;

#endif