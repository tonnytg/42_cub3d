/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:55:00 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/05 22:58:32 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_game	*load_game(t_game *game, int argc, char **argv)
{
	printf("load game %d %s - game: %p\n", argc, argv[0], game);
	return (game);
}
