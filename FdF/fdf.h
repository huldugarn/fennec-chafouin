/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 12:10:56 by rle-corr          #+#    #+#             */
/*   Updated: 2016/06/28 15:00:08 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include <stdlib.h>
# define WIN_W 1600
# define WIN_H 900
# define WIN_N "Joie et bonheur"
# define TILE_W 64
# define TILE_H 64

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_image
{
	void			*ptr;
	int				bpx;
	int				szl;
	int				end;
}					t_i;

typedef struct		s_param
{
	void			*mlx;	//	pointeur vers adresse de référence entre Xlib et executable
	void			*win;	//	pointeur vers adresse de la fenetre
	t_i				*ima;
	char			*ima_data;
	int				tile_w;
	int				tile_h;
	int				gs_x;	//	grid size x axis
	int				gs_y;	//	grid size y axis
	int				print;
	char			*map_path;
}					t_param;

#endif
