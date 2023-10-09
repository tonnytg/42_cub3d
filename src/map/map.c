/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:38:54 by antthoma          #+#    #+#             */
/*   Updated: 2023/10/09 15:04:12 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	read_map(t_game *game)
{
    char	buffer[1024];
    char	line[MAX_LINE_SIZE];
    size_t	line_size = 0;
    ssize_t	bytes_read;
	ssize_t	i;

	while ((bytes_read = read(game->map->fd, buffer, sizeof(buffer))) > 0)
	{
        // TODO: Realizar a leitura do arquivo
		// e salvar em uma estrutura que faça sentido.
		i = 0;
		while (i < bytes_read)
        {
			if (buffer[i] == '\n')
            {
				// Processar a linha lida
				line[line_size] = '\0'; // Adicionar terminador nulo
				printf("Linha lida: %s\n", line);
				line_size = 0;
			}
            else if (line_size < MAX_LINE_SIZE - 1)
            {
                // Adicionar o caractere ao buffer da linha, se houver espaço
                line[line_size++] = buffer[i];
            }
            else
            {
                // A linha é muito longa, trate esse erro adequadamente
                fprintf(stderr, "Erro: linha muito longa\n");
                exit(1);
            }
		}
    }
    if (bytes_read == -1)
    {
        perror("Erro na leitura do arquivo");
        exit(1);
    }
    if (line_size > 0)
    {
        // Processar a última linha, se houver alguma
        line[line_size] = '\0'; // Adicionar terminador nulo
        printf("Linha lida: %s\n", line);
    }		
	return (0);
}
