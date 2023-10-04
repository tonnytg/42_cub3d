/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:49:23 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/04 05:00:15 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (check_arguments(argc, argv))
		return (1);
	ft_calloc(1, sizeof(t_game));
	load_settings(game, argc, argv);
	start_game(game);
	finish_game(game);
	return (0);
}
