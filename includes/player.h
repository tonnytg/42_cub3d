/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:16:27 by lbiasuz           #+#    #+#             */
/*   Updated: 2023/10/28 16:20:43 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define FOV 90
# define FOV_LENGTH 550
# define TURN_SPEED 5
# define MOVE_SPEED 0.5
# define PLAYER_SIZE 2

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_fov_line
{
	t_point	beg;
	t_point	end;
	t_point	dist;
	t_point	step;
	double	len;
	double	angle;
	int		err;
	char	wall_side;
}	t_fov_line;

typedef struct s_player
{
	t_fov_line	line[FOV];
	double		x;
	double		y;
	double		angle;
}	t_player;

#endif