/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:55:58 by rle-corr          #+#    #+#             */
/*   Updated: 2016/03/17 14:53:32 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "~/Projects/Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_opt
{
	int				nata;	//	next argument to access
	int				altf;	//	# alternate conversion form
	int				zpad;	//	0 zero padding
	int				bpad;	//	- blank padding
	int				asig;	//	  aligned signed numbers
	int				esig;	//	+ explicit signed numbers
	int				tsep;	//	' thousands separator
	int				mfwd;	//	minimum field width
	int				lmod;	//	length modifier
}					t_opt;

typedef struct		s_arg
{
	int				i;		//	argument numéro i
	char			type;	//	type de conversion
	t_opt			opt;	//	options & attributs
}

void	va_start(va_list vl, last);
type	va_arg(va_list vl, type);
void	va_end(va_list vl);
int		ft_printf(const char * restrict format, ...);

#endif
