/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:48:44 by selbouka          #+#    #+#             */
/*   Updated: 2025/02/24 21:25:06 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../ft_printf/ft_printf.h"
#include "../get_next_line/get_next_line.h"


#include <mlx.h>

#include <unistd.h>

typedef	struct mlx_stuff
{
	// void	*wall_img;
	// void	*player_img;
	// void	*coll_img;
	// void	*exit_img;
	// void	*floor_img;

}	t_mlx;

typedef struct game_obj
{
	char	**map;
	int		rows;
	int		colums;
	int		ply_x;
	int		ply_y;
	int		collec;
	int		total_collec;
	int		exit;
	int		player;
	int		exit_valid;
	// struct mlx_stuff		*mlx;
	void	*img;
	void	*mlx_connect;
	void	*mlx_wind;
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
int	ft_strlcpy(char *dst, const char *src, int size);
char	*ft_strdup(const char *src);
void	flood_fill(char **matrice, int x, int y, t_game *data);
int	lines_equal(char *line, int size);

// Map stuff
void	read_map(t_game *data, char *path);
void	save_map(t_game	*data, char *av);
void 	zeroos(t_game *d);
int	key_handle(int key, t_game *data);

// Error
void err(int i);
void map_err(int i, int fd);

// mlx stuff
void put_map(t_game	*data);

#endif
