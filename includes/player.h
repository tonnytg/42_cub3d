/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:16:27 by lbiasuz           #+#    #+#             */
/*   Updated: 2023/10/21 15:58:15 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define FOV 60
# define FOV_LENGTH 550
# define TURN_SPEED 10
# define MOVE_SPEED 4
# define PLAYER_SIZE 0

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_fov_line
{
	int	id;
	t_point	beg;
	t_point	end;
	t_point	dist;
	t_point	step;
	double	line_length;
	int	angle;
	int	err;
	int	e2;
	int color;
}	t_fov_line;

typedef struct s_player
{
	t_fov_line		line[FOV];
	int				x;
	int				y;
	float			angle;
	int				moved;
	int				collected;
}	t_player;

#endif