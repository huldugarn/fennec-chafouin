/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 11:33:33 by rle-corr          #+#    #+#             */
/*   Updated: 2016/01/31 16:48:25 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define XF '#'
# define XE '.'
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_coords
{
	int			y;
	int			x;
	int			tx[4];
	int			ty[4];
}				t_coords;
/*
**	in main.c
*/
int				main(int argc, char **argv);
int				ft_resolution(char **tab, char ***grid, int side, int i);
void			ft_annex(t_coords *tyx, int side);
void			ft_free(char ***grid, int side);
/*
**	in read.c
*/
int				ft_tetracontrol(char *tetra);
char			*ft_line(char *buffer);
int				ft_gridcontrol(char *buffer, int rr);
char			*ft_read(int fd, int *s_rr);
char			**ft_tab(char *file);
/*
**	in resolve.c
*/
char			**ft_grid(char **tab, int n, int *s);
void			ft_coords(int (*tyx)[4], char *line, int opt);
int				ft_validposition(int side, t_coords *tyx, char ***grid);
void			ft_place(char ***grid, t_coords tyx, int i, char c);
/*
**	in display.c
*/
void			ft_display(char **grid, int s);
/*
**	in error.c
*/
void			ft_error(int code);

#endif
