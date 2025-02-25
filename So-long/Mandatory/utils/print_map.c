/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:45:04 by selbouka          #+#    #+#             */
/*   Updated: 2025/02/25 10:06:04 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	key_handle(int key, t_game *data)
{
	ft_printf("%d\n", key);
	data->collec = data->collec;
	return 0;
}

void	trnsf_img(t_game *data, int x, int y, char *path)
{
	int	img_w;
	int	img_h;
	ft_printf("path = %s\n", path);
	data->img = mlx_xpm_file_to_image(data->mlx_connect, path, &img_w, &img_h);
	if (!data->img)
		err(26);
	mlx_put_image_to_window(data->mlx_connect, data->mlx_wind, data->img, x, y);
}

void	put_img(char type, int x_p, int y_p, t_game *data)
{
	if (type == '1')
		trnsf_img(data, x_p, y_p, "../textures/wall.xpm");
	else if (type == 'P')
	{
		data->ply_x = x_p;
		data->ply_y = y_p;
		trnsf_img(data, x_p, y_p, "../textures/floor.xpm");
		trnsf_img(data, x_p, y_p, "../textures/player.xpm");
	}
	else if (type == 'C')
	{
		trnsf_img(data, x_p, y_p, "../textures/floor.xpm");
		trnsf_img(data, x_p, y_p, "../textures/coins.xpm");
		data->total_collec++;
	}
	else if (type == 'E')
		trnsf_img(data, x_p, y_p, "../textures/exit.xpm");
	else
		trnsf_img(data, x_p, y_p, "../textures/floor.xpm");
}

void put_map(t_game	*data)
{
	int	x_map;
	int	y_map;
	int	x_px;
	int	y_px;
	int	w_tmp;

	y_map = 0;
	y_px = 0;
	w_tmp = data->colums;
	while (data->rows)
	{
		x_map = 0;
		x_px = 0;
		while (data->colums)
		{
			put_img(data->map[y_map][x_map], x_px, y_px, data);
			x_map++;
			y_px += 50;
			data->colums--;
		}
		data->rows--;
		y_map++;
		x_px += 50;
		data->colums = w_tmp;
	}
}














	// path = "./xmp";
	// data->mlx_wind =  mlx_xpm_file_to_image(data->mlx->mlx_connect, path,&data->colums,&data->rows);
	// mlx_key_hook(data->mlx->mlx_wind, NULL, &data);
	// mlx_hook(data->mlx->mlx_wind, 17, (1L << 0), NULL ,&data);
	// mlx_loop(data->mlx->mlx_connect);