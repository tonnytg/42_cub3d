/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:49:35 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/09 15:01:02 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

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

int	check_format_file(int argc, char **argv)
{
	int	total;

	if (argc != 2)
		return (1);
	total = ft_strlen(argv[1]);
	if (total != 0)
		if (argv[1][total - 1] == 'b')
			if (argv[1][total - 2] == 'u')
				if (argv[1][total - 3] == 'c')
					if (argv[1][total - 4] == '.')
						return (0);
	return (1);
}

int	is_invalid_map(int argc, char **argv)
{
	if ((argc == 2 && ft_strlen(argv[1]) < 5)
		|| check_format_file(argc, argv))
	{
		ft_printf("ERROR: wrong map!\n");
		return (1);
	}
	return (0);
}

int	is_invalid_map_file(int argc, char **argv)
{
	if (is_invalid_arguments(argc, argv)
		|| is_invalid_map(argc, argv))
		return (1);
	return (0);
}
