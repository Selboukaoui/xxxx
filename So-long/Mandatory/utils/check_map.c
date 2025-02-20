/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:41:47 by selbouka          #+#    #+#             */
/*   Updated: 2025/02/20 18:52:07 by selbouka         ###   ########.fr       */
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
		return(ft_printf("Open error\n"),exit(0)); //check leaks later
	line = get_next_line(fd);
	if (!line)
		map_err(25, fd);
	data->columns = ft_strlen(line);
	while (line)
	{
		if (data->columns != ft_strlen(line))
			map_err(25, fd);
		line = get_next_line(fd);
		data->rows++;
	}
	if (data->rows == 0)
		map_err(25, 0);
	close (fd);
}
