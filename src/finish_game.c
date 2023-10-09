/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:54:42 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/09 20:30:55 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_game	*finish_game(t_game *game)
{
	printf("finish game %p!\n", game);
	free(game->map);
	free(game->engine);
	free(game);
	return (NULL);
}
