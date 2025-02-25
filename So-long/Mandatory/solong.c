/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:39:03 by selbouka          #+#    #+#             */
/*   Updated: 2025/02/25 09:54:45 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int main(int ac, char **av)
{
	t_game	*data;

	data = ft_malloc(sizeof(t_game), 1);
	if (!data)
		err(26);
	zeroos(data);
	if (ac != 2)
	{
		ft_printf ("Erorr !!\n./solong  <Map name.ber>\n");
		return (0);
	}
	read_map(data, av[1]);
	save_map(data, av[1]);
	
	data->mlx_connect = mlx_init();
	data->mlx_wind = mlx_new_window(data->mlx_connect, data->colums * 50,
							data->rows * 50, "So-Long");
	put_map(data);
	// mlx_key_hook(data->mlx->mlx_wind, key_handle, data);
	mlx_loop(data->mlx_connect);

}

	// int i = 0, j = 0;
	// 	while (data->map[i])
	// {
	// 	j = 0;
	// 	while (data->map[i][j])
	// 	{
	// 		ft_printf("%c",data->map[i][j]);
	// 		j++;
	// 	}
	// 	// ft_printf("\n");
	// 	i++;
	// }






















