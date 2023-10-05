/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:49:35 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/04 23:38:56 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	is_invalid_arguments(int argc, char **argv)
{
	printf("%s - %d\n", argv[1], argc);
	if (argc != 2
		|| (argv[1] == NULL))
	{
		printf("1\n");
		return (1);
	}
	return (0);
}

int	is_invalid_map(int argc, char **argv)
{
	if (argc == 2 
		&& ft_strlen(argv[1]) < 5)
	{
		ft_printf("ERROR: wrong map!\n");
		return (1);
	}
	return (0);
}

int	check_arguments(int argc, char **argv)
{
	if (is_invalid_arguments(argc, argv)
		|| is_invalid_map(argc, argv))
		return (1);
	return (0);
}
