/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:16:27 by lbiasuz           #+#    #+#             */
/*   Updated: 2023/10/16 22:44:45 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct s_player_fov
{
	int	id;
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	color;
}	t_player_fov;

typedef struct s_player_line
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
	int color;
}	t_player_line;

typedef struct s_player_circle
{
	int	x_center;
	int	y_center;
	int	radius;
	int	color;
	int	x;
	int	y;
	int	p;
}	t_player_circle;


typedef struct s_player
{
	t_player_fov	*fov_line;
	t_player_line	*line;
	t_player_circle	*circle;
	int				x;
	int				y;
	float			angle;
	int				moved;
	int				collected;
}	t_player;


#endif