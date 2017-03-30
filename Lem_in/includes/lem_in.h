/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 11:20:05 by rle-corr          #+#    #+#             */
/*   Updated: 2017/01/24 11:20:22 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../Libft/libft.h"
# include "../Libft/get_next_line.h"

typedef struct	s_coords
{
	int			x;
	int			y;
}				t_coords;

typedef struct	s_room
{
	int			depth;
	int			links;
	char		*name;
	t_coords	p;
}				t_room;

typedef struct	s_lmn
{
	int			fd;

	int			n_ants;		//ants amount
	int			n_rooms;	//room amount
	int			c_rooms;	//room counter
	int			n_links;	//link amount
	char		*buffer;
	char		*record;
	t_room		*s_room;	//start room
	t_room		*e_room;	//end room
	t_list		*rooms;	//room list
}				t_lmn;

/*
**	main.c
*/

int				main(void);

/*
**	read.c
*/

int				lem_in_read(t_lmn *s);

/*
**	play.c
*/

//void			filler_play(t_flr *fsp);

/*
**	note.c
*/

//void			filler_note(t_flr *s);

#endif