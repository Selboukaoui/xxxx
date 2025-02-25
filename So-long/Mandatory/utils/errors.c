/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:43:55 by selbouka          #+#    #+#             */
/*   Updated: 2025/02/22 14:59:56 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void err(int i)
{
	if (i == 25 || i == 26 || i == -1)
		ft_malloc(0, 0);
	if (i == 26)
		ft_printf("Error\nAllocation failed\n");
	if (i == -1)
		ft_printf("Error\n");
	exit(0);
}

void map_err(int i, int fd)
{
	ft_printf ("Map Error\n");
	if (fd != -1)
		close(fd);
	if (i == 25)
		err(25);
	err(0);
}