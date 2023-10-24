/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:16:27 by lbiasuz           #+#    #+#             */
/*   Updated: 2023/10/23 21:19:52 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define FOV 60
# define FOV_LENGTH 550
# define TURN_SPEED 2
# define MOVE_SPEED 5
# define PLAYER_SIZE 2

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_fov_line
{
	int		d;
	t_point	beg;
	t_point	end;
	t_point	dist;
	t_point	step;
	double	line_length;
	int		angle;
	int		err;
	int		e2;
	int		color;
	char	wall_side; // 'N', 'S', 'E', or 'W'
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