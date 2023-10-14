#include <cub3D.h>

void print_map_prompt(t_game *game)
{
	printf("print map\n");
    for (int i = 0; i < game->map->lines; i++)
    {
        for (int j = 0; j < game->map->columns; j++)
        {
            printf("%c", game->map->grid[i][j]); // Imprime o caractere na posição (i, j)
        }
        printf("\n"); // Muda para a próxima linha do mapa
    }
	printf("end print map\n");
}
