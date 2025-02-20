/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:43:55 by selbouka          #+#    #+#             */
/*   Updated: 2025/02/20 18:33:46 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void err(int i)
{
	if (i == 25 || i == 26)
		ft_malloc(0, 0);
	if (i == 26)
		ft_printf("Allocation failed\n");
	exit(0);
}

void map_err(int i, int fd)
{
	ft_printf ("Error\nMap invalid\n");
	if (fd != -1)
		close(fd);
	if (i == 25)
		err(25);
	err(0);
}