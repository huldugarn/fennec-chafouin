/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 12:10:56 by rle-corr          #+#    #+#             */
/*   Updated: 2016/06/02 16:07:30 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include <stdlib.h>
# define WIN_WIDTH 1600
# define WIN_HEIGHT 900
# define WIN_NAME "Joie et bonheur"

typedef struct		s_param
{
	void			*mlx;
	void			*win;
	int				x;
	int				y;
}					t_param;

#endif
