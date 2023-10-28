/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:16:27 by lbiasuz           #+#    #+#             */
/*   Updated: 2023/10/28 11:38:41 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define FOV 60
# define FOV_LENGTH 550
# define TURN_SPEED 10
# define MOVE_SPEED 2
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
	int		angle;
	int		err;
	char	wall_side;
}	t_fov_line;

typedef struct s_player
{
	t_fov_line	line[FOV];
	float		x;
	float		y;
	float		angle;
}	t_player;

#endif