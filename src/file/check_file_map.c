/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:49:35 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/30 13:55:18 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	invalid_arguments(int argc, char **argv)
{

	if (argc == 2 && (argv[1] != NULL))
		return (0);
	ft_printf("Error\ninvalid_number_of_arguments!\n");
	return (1);
}

static int	invalid_extension(char **argv)
{
	int	s;

	s = ft_strlen(argv[1]);
	if (s != 0 && ft_strnstr(&(argv[1][s - 4]), ".cub", 4))
		return (0);
	ft_printf("Error\nwrong file or file extension!\n");
	return (1);
}

int	invalid_map_file(int argc, char **argv)
{
	return (invalid_arguments(argc, argv) || invalid_extension(argv));
}
