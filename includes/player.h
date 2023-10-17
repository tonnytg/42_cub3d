/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:16:27 by lbiasuz           #+#    #+#             */
/*   Updated: 2023/10/17 19:40:43 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define FOV 60
# define PLAYER_SIZE 4

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_fov_line
{
	int	id;
	int	color;
	t_point	beg;
	t_point	end;
}	t_fov_line;

typedef struct s_player_line
{
	t_point	beg;
	t_point	end;
	t_point	dist;
	t_point	step;
	int	err;
	int	e2;
	int color;
}	t_player_line;

typedef struct s_player
{
	t_fov_line	*fov_line;
	t_player_line	*line;
	int				x;
	int				y;
	float			angle;
	int				moved;
	int				collected;
}	t_player;

#endif