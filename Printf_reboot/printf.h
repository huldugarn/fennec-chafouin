/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:30:01 by rle-corr          #+#    #+#             */
/*   Updated: 2016/09/29 15:30:06 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <inttypes.h>

/*
**	
**	ctyp		(char ID)	conversion type
**	flag		
**	pads		(switch)	padding side : left "l" or right "r"
**	alternate	(boolean)	
**	negation	(boolean)	
**	ncex		(boolean)	null-character exception
**	prec		(value)		precision
**	prec_flag	(boolean)	precision flag
**	mfwd		(value)		minimum field width
**	mfwd_flag	(boolean)	minimum field width flag
**	lmod		(char ID)	length modifier
**	ascii_str	(string)	ascii string
**	wchar_str	(string)	wide char string
**	
*/

typedef struct	pfs
{
	char		ctyp;
	char		flag;
	char		pads;
	int			prec;
	int			prec_flag;
	int			mfwd;
	int			mfwd_flag;
	int			altf;
	int			negation;
	int			ncex;
	char		lmod[3];
	char		*ascii_str;
	wchar_t		*wchar_str;

}				t_pfs;

#endif
