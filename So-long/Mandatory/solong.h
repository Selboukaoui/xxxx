/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:48:44 by selbouka          #+#    #+#             */
/*   Updated: 2025/02/20 15:24:32 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../ft_printf/ft_printf.h"
#include "../get_next_line/get_next_line.h"
#include <mlx.h>
#include <unistd.h>

typedef struct game_obj
{
	char	**map;
	int		rows;
	int		columns;
	int		ply_x;
	int		ply_y;
	int		collec;
	int		total_collec;
	int		exit;

}	t_game;

typedef struct garbage_c
{
	void				*data;
	struct garbage_c	*next;
}	t_collect;

// Utils
long	ft_atoi(const char *str);
int	ft_strcmp(char *s1, char *s2);
int	ft_strlen(const char *str);
void	*ft_malloc(size_t size, int mode);
void	read_map(t_game *data, char *path);

// Error
void err(int i);
void map_err(int i, int fd);

#endif
