/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 05:06:23 by antthoma          #+#    #+#             */
/*   Updated: 2023/11/02 14:37:20 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	strip_newline(char *str)
{
	int	len;

	len = strlen(str);
	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
	}
}

int	is_number(const char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	count_rgb(int i)
{
	if (i != 3)
	{
		printf("Error\nRGB must need 3 values\n");
		return (1);
	}
	return (0);
}

int	is_invalid_color(char *line)
{
	char	**temp;
	char	**rgb;
	int		i;

	strip_newline(line);
	temp = ft_split(line, ' ');
	rgb = ft_split(temp[1], ',');
	free_array(temp);
	i = 0;
	while (rgb[i] != NULL)
	{
		if (!is_number(rgb[i]))
		{
			printf("Error\nRGB value is not a valid integer\n");
			free_array(rgb);
			return (1);
		}
		i++;
	}
	free_array(rgb);
	if (count_rgb(i))
		return (1);
	return (0);
}
