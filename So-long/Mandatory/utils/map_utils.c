/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:42:05 by selbouka          #+#    #+#             */
/*   Updated: 2025/02/22 20:37:55 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void zeroos(t_game *d)
{
	d->collec = 0;
	d->rows = 0;
	d->colums = 0;
	d->exit = 0;
	d->ply_x = 0;
	d->ply_y = 0;
	d->total_collec = 0;
	d->player = 0;
	d->exit_valid = 0;
}

void	flood_fill(char **matrice, int x, int y, t_game *data)
{
	if (x < 0 || y < 0 || x >= data->rows|| y >= data->colums)
		return ;
	if (matrice[x][y] == '1' || matrice[x][y] == 'X')
		return ;
	if (matrice[x][y] == 'C')
		data->collec++;
	if (matrice[x][y] == 'E')
		data->exit_valid = 1;
	matrice[x][y] = 'X';
	flood_fill(matrice, x + 1, y, data);
	flood_fill(matrice, x - 1, y, data);
	flood_fill(matrice, x, y + 1, data);
	flood_fill(matrice, x, y - 1, data);
}

int	lines_equal(char *line, int size)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	return (len == size);
}