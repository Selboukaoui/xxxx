/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:41:47 by selbouka          #+#    #+#             */
/*   Updated: 2025/02/23 09:58:25 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	read_map(t_game *data, char *path)
{
	int		fd;
	char	*line;

	if (!path || !ft_strcmp(path + ft_strlen(path) - 4, ".ber" ) )
		map_err(25, -1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		err(26);
	line = get_next_line(fd);
	if (!line)
		map_err(25, fd);
	data->colums = ft_strlen(line) - 1;
	while (line)
	{
		// ft_printf("%d--%s", data->rows, line);
		if (!lines_equal(line, data->colums))
			map_err(25, fd);
		line = get_next_line(fd);
		data->rows++;
	}
	close (fd);
	if (data->rows == 0)
		map_err(25, 0);
}

void	characters_check(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows - 1)
	{
		j = 0;
		while(j < data->colums - 1)
		{
			if (data->map[i][j] == 'P')
			{
				data->ply_x = i;
				data->ply_y = j;
				data->player++;
			}
			else if (data->map[i][j] == 'E')
				data->exit++;
			else if (data->map[i][j] == 'C')
				data->total_collec++;
			else if (data->map[i][j] != '1' && data->map[i][j] != '0')
				map_err(25, -1);
			j++;
		}
		i++;
	}
}

void	corners_check(t_game *data)
{
	int	i;	
	int	j;

	i = 0;
	while(i < data->rows - 1)
	{
		j = 0;
		while (j < data->colums - 1)
		{
			if (data->map[0][j] != '1' || data->map[data->rows - 1][j] != '1')
				map_err(25, -1);
			if (data->map[i][data->colums - 1] != '1' || data->map[i][0] != '1')
				map_err(25, -1);
			j++;
		}
		i++;
	}
	characters_check(data);
	if (data->exit != 1 || data->player != 1 || data->total_collec <= 0)
		map_err(25, -1);
}

void	route_check(t_game	*data)
{
	char	**map_cpy;
	int				i;
	
	map_cpy = malloc(sizeof(char *) * data->rows);
	if (!map_cpy)
		err(26);
	i = 0;
	while (i < data->rows)	
	{
		map_cpy[i] = ft_strdup(data->map[i]);
		i++;
	}
	flood_fill(map_cpy, data->ply_x, data->ply_y, data);
	if (data->collec != data->total_collec || data->exit_valid != 1)
		map_err(26, -1);
	// ft_printf ("%d -- %d -- %d",data->collec, data->total_collec, data->exit_valid  );
}

void	save_map(t_game	*data, char *av)
{
	int	fd;
	int	i;
	char	*line;
	
	i = 0;
	data->map = ft_malloc(sizeof(char *) * data->rows, 1);
	if (!data->map)
		err(26);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		err(-1);
	while (i < data->rows)
	{
		line = get_next_line(fd);
		if (!line)
			map_err(25, fd);
		// ft_printf ("\n%i -- %s",i,line);
		data->map[i] = ft_malloc(data->colums + 1, 1);
		if (!data->map[i])
			err(26);
		ft_strlcpy(data->map[i], line, data->colums + 1); // +1	
		i++;
	}
	corners_check(data);
	route_check(data);
}
