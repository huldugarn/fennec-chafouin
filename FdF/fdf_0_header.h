/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_0_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 15:54:35 by rle-corr          #+#    #+#             */
/*   Updated: 2016/08/16 15:38:19 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_0_HEADER_H
# define FDF_0_HEADER_H

# include "mlx.h"
# include "./Libft/libft.h"
# include "./Libft/get_next_line.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define WIN_N "Liesse, Langueur & Nonchalance"
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

# define IN___ 5
# define OUT__ 0
# define UP___ 8
# define DOWN_ 2
# define LEFT_ 4
# define RIGHT 6
# define MORE_ '+'
# define LESS_ '-'

# define KB_ESC 53
# define KB_RET 36
# define KB_DEL 51
# define KB_L_CTL 256
# define KB_R_CTL 269
# define KB_L_SFT 257
# define KB_R_SFT 258
# define KB_L_CMD 259
# define KB_R_CMD 260
# define KB_L_ALT 261
# define KB_R_ALT 262
# define KB_A 0
# define KB_B 11
# define KB_C 8
# define KB_D 2
# define KB_E 14
# define KB_F 3
# define KB_H 4
# define KB_I 34
# define KB_J 38
# define KB_K 40
# define KB_L 37
# define KB_M 46
# define KB_N 45
# define KB_O 31
# define KB_P 35
# define KB_Q 12
# define KB_R 15
# define KB_S 1
# define KB_T 17
# define KB_U 32
# define KB_V 9
# define KB_W 13
# define KB_X 7
# define KB_Y 16
# define KB_Z 6
# define KB_1 18
# define KB_2 19
# define KB_3 20
# define KB_4 21
# define KB_5 23
# define KB_6 22
# define KB_7 26
# define KB_8 28
# define KB_9 25
# define KB_0 29
# define KB_MINUS 27
# define KB_EQUAL 24
# define NP_DOT 65
# define NP_PLUS 69
# define NP_MINUS 78
# define NP_0 82
# define NP_1 83
# define NP_2 84
# define NP_3 85
# define NP_4 86
# define NP_5 87
# define NP_6 88
# define NP_7 89
# define NP_8 91
# define NP_9 92
# define AR_L 123
# define AR_R 124
# define AR_D 125
# define AR_U 126
# define PG_U 116
# define PG_D 121

/*
**	0 - Structures
*/
typedef struct		s_point
{
	int				x;
	int				x_p;
	int				y;
	int				y_p;
	int				z;
	int				z_c;
	int				c;
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
	char			*map_path;
	void			*mlx;
	void			*win;
	void			*ima;
	char			*ima_data;
	int				ima_bits;
	int				ima_line;
	int				ima_endi;
	t_p				**grid;
	int				gs_x;
	int				gs_y;
	int				z_max;
	int				gap_surface;
	int				gap_volume;
	float			angle;
	int				x_translate;
	int				y_translate;
}					t_e;

/*
**	1 - Main
*/
int					main(int argc, char **argv);
void				map_processing(t_e *e);
int					end_exe(t_e *e);

/*
**	2 - Auxiliary - Input parsing
*/
t_p					**create_grid(t_e *e);
t_p					*create_y_points_list(t_e *e, char *buffer, int y);
t_p					create_point(int x, int y, int z);
int					map_size(char *map_path);
int					tab_size(t_p **tab);

/*
**	3 - Auxiliary - Hooks
*/
int					expose_hook(t_e *e);
void				expose_hook_reset(t_e *e);
int					key_hook(int keycode, t_e *e);
int					key_hook_press(int keycode, t_e *e);
int					mouse_hook(int button, int x, int y, t_e *e);

/*
**	4 - Auxiliary - Interactions
*/
void				zoom(t_e *e, int order);
void				translation(t_e *e, int order);
void				rotation(t_e *e, int order);
void				extrusion(t_e *e, char order);
void				reset(t_e *e);

/*
**	5 - Auxiliary - Calculations
*/
void				calculation_full(t_e *e);
void				calculation_point(t_e *e, t_p *p);
int					display_inclusion(t_e *e, int n, char c);
int					translate(t_e *e, int n, char c);

/*
**	6 - Auxiliary - Drawing
*/
void				draw_full(t_e *e);
void				draw_line(t_e *e, t_p *a, t_p *b);
void				draw_pixl(t_e *e, int x, int y, int color);
t_b					*bresenham_init(t_p *a, t_p *b, int z_max, int volume);
int					color_selection(int a_z, int b_z, int z_max, int volume);

#endif
