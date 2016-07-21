/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 12:10:56 by rle-corr          #+#    #+#             */
/*   Updated: 2016/07/21 16:22:32 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "./Libft/libft.h"
# include "./Libft/get_next_line.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define WIN_N "Joie et bonheur"
# define WIN_W 1600
# define WIN_H 900
# define TILE_W 64
# define TILE_H 64

# define BLK 0x000000
# define MRN 0x800000
# define RED 0xFF0000
# define ORG 0xFF8000
# define YLW 0xFFFF00
# define GRN 0x00FF00
# define CYN 0x00FFFF
# define BLU 0x0000FF
# define PRP 0x800080
# define GRY 0x808080
# define WHT 0xFFFFFF

typedef struct		s_point
{
	int				x;
	int				x_p;	//	x prime
	int				y;
	int				y_p;	//	y prime
	int				z;
	int				color;
}					t_p;

typedef struct		s_bresenham
{
	int				delta_x;
	int				delta_y;
	int				delta_error;
	int				sign_x;
	int				sign_y;
}					t_b;

typedef struct		s_envelope
{
	void			*mlx;		//	pointeur vers adresse de référence Xlib/exe
	void			*win;		//	pointeur vers adresse de la fenetre
	void			*ima;
	char			*ima_data;	//	image data
	int				ima_bits;	//	image bits per pixel
	int				ima_line;	//	image line size
	int				ima_endi;	//	image endian
	char			*map_path;
	t_point			**grid;
	int				gs_x;		//	grid size x axis
	int				gs_y;		//	grid size y axis
	int				z_max;		//	max value z axis
	int				gap_surface;//	écart des points en surface
	int				gap_volume;	//	écart des points en volume
	int				angle;
	int				x_translate;
	int				y_translate;
}					t_e;

/*
**	Main
*/

/*
**	Auxiliary - Input parsing
*/
t_point				**create_grid(t_param *p);
t_point				*create_y_points_list(t_param *p, char *str, int y);
t_point				create_point(int x, int y, int z);
int					map_size(char *map_path);
int					tab_size(t_point **tab);

/*
**	Auxiliary - Hooks
*/


/*
**	Auxiliary - Calculations
*/
void				calculation_full(t_e *e);
void				calculation_point(t_e *e, t_p *p);
int					display_inclusion(t_e *e, int n, char c);
int					translate(t_e *e, int n, char c);

/*
**	Auxiliary - Drawing
*/
void				draw_full(t_e *e);
void				draw_line(t_e *e, t_p *a, t_p *b);
void				draw_pixel(t_e *e, int x, int y, int color);
t_b					bresenham_init(t_p *a, t_p *b, int z_max);
int					color_selection(int a_z, int b_z, int z_max);

/*
**	Auxiliary - Interactions
*/


#endif
