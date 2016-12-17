/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:04:08 by rle-corr          #+#    #+#             */
/*   Updated: 2016/11/22 13:10:28 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include "../Libft/libft.h"
# include "../Libft/get_next_line.h"

typedef struct	s_coords
{
	int			x;
	int			y;
}				t_coords;

typedef struct	s_grd
{
	int			w;
	int			h;
	t_coords	p;
	char		**data;
}				t_grd;

typedef struct	s_flr
{
	int			turn;	// tour de jeu
	int			p_nb;	// numéro du joueur
	char		pawn;	// couleur de pion ('o' ou 'x')
	int			Oscr;	// score du joueur 'o'
	int			Xscr;	// score du joueur 'x'
//	int			mapX;	// largeur du plateau
//	int			mapY;	// hauteur du plateau
	t_coords	posO;	// position initiale du joueur 'o'
	t_coords	posX;	// position initiale du joueur 'x'

}				t_flr;
#endif
