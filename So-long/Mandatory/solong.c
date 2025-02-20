/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:39:03 by selbouka          #+#    #+#             */
/*   Updated: 2025/02/20 18:54:29 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void zeroos(t_game *d)
{
	d->collec = 0;
	d->rows = 0;
	d->columns = 0;
	d->exit = 0;
	d->ply_x = 0;
	d->ply_y = 0;
	d->total_collec = 0;
}
int main(int ac, char **av)
{
	t_game	*data;

	data = malloc (sizeof(t_game));
	if (!data)
		err(26);
	zeroos(data);
	if (ac != 2)
	{
		ft_printf ("Erorr !!\n./solong  <Map name.ber>\n");
		return (0);
	}
	read_map(data, av[1]);
	save_map();
	
}