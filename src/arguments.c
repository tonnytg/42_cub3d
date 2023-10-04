/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:49:35 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/04 05:02:14 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_invalid_arguments(int argc, char **argv)
{
	if (argc <= 1)
	{
		return (1);
	}
	if (argv == NULL)
	{
		return (1);
	}
	return (0);
}

int	is_invalid_map(int argc, char **argv)
{
	printf("check map %d %s\n", argc, argv[0]);
	return (0);
}
