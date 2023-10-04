#include "../includes/cub3d.h"

int	is_invalid_arguments(int argc, char *argv[])
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

