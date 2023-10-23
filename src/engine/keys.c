/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:38:24 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/21 17:11:11 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

double round_to_n_decimal_places(double value, int n) {
    double multiplier = pow(10.0, n);
    return round(value * multiplier) / multiplier;
}

int	key_press(int keycode, t_game *game)
{
	game->i++;
	if (keycode == ESC)
		exit_game(game);
else if (keycode == UP || keycode == UP2)
{
    // printf("key up pressed\n");
    game->player->x += MOVE_SPEED * cos(game->player->angle * (M_PI / 180.0));
    game->player->y += MOVE_SPEED * sin(game->player->angle * (M_PI / 180.0));
}
else if (keycode == DOWN || keycode == DOWN2)
{
    // printf("key down pressed\n");
    game->player->x -= MOVE_SPEED * cos(game->player->angle * (M_PI / 180.0));
    game->player->y -= MOVE_SPEED * sin(game->player->angle * (M_PI / 180.0));
}
else if (keycode == RIGHT || keycode == RIGHT2) {
    // printf("key right pressed\n");
    game->player->angle += TURN_SPEED;
    if (game->player->angle >= 360.0) // Se o ângulo exceder 360, subtrair 360
        game->player->angle -= 360.0;
}
else if (keycode == LEFT || keycode == LEFT2) {
    // printf("key left pressed\n");
    game->player->angle -= TURN_SPEED;
    if (game->player->angle < 0) // Se o ângulo for negativo, adicionar 360
        game->player->angle += 360.0;
}
	render_game(game);
	// printf("player x: %d\n", game->player->x);
	// printf("player y: %d\n", game->player->y);
	// printf("player angle: %f\n", game->player->angle);
	return (0);
}