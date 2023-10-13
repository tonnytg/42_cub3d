/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:49:23 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/13 04:32:29 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	main(int argc, char **argv)
{
	t_game	*game;

	if (is_invalid_map_file(argc, argv))
		return (1);
	game = ft_calloc(1, sizeof(t_game));
	if (game == NULL)
	{
		printf("Error\nNot enough resources available to allocate memory.");
		return (1);
	}
	load_game(game, argv);
	start_game(game);
	finish_game(game);
	return (0);
}
