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

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <inttypes.h>
# include "./Libft/libft.h"
# define PF_FC " .*#+-0123456789hjlLz"

/*
**	ctyp		(char ID)	conversion type
**	flag
**	pads		(switch)	padding side : left "l" or right "r"
**	prec		(value)		precision
**	prec_flag	(boolean)	precision flag
**	mfwd		(value)		minimum field width
**	mfwd_flag	(boolean)	minimum field width flag
**	altf		(boolean)	alternate form
**	negation	(boolean)
**	ncex		(boolean)	null-character exception
**	lmod		(char ID)	length modifier
**	ascii_str	(string)	ascii string
**	wchar_str	(string)	wide char string
*/

typedef struct	s_pfs
{
	char		ctyp;
	char		sign;
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

/*
**	main.c		main functions, color functions
*/
int				ft_printf(const char *restrict format, ...);

/*
**	aux0.c
*/
int				pf_read_and_display(const char *restrict format, va_list *vl);

/*
**	aux1.c		check options functions
*/
void			pf_check_pads(t_pfs *pfs, const char *restrict format);
void			pf_check_lmod(t_pfs *pfs, const char *restrict format);
void			pf_check_prec_mfwd(t_pfs *pfs, const char *restrict format,
				va_list *vl);
void			pf_check_prec(t_pfs *pfs, const char *restrict format,
				va_list *vl, int *i);
void			pf_check_mfwd(t_pfs *pfs, const char *restrict format,
				va_list *vl, int *i);

/*
**	aux2.c		conversions functions, part 1/2
*/
void			pf_conversion_hub1(va_list *vl, t_pfs *pfs);
void			pf_conversion_hub2(va_list *vl, t_pfs *pfs);
void			pf_conv_wchar(va_list *vl, t_pfs *pfs);
void			pf_conv_char(va_list *vl, t_pfs *pfs);
void			pf_conv_integer(va_list *vl, t_pfs *pfs);

/*
**	aux3.c		conversions functions, part 2/2
*/
void			pf_conv_octal(va_list *vl, t_pfs *pfs);
void			pf_conv_unsigned(va_list *vl, t_pfs *pfs);
void			pf_conv_hexadecimal(va_list *vl, t_pfs *pfs);
void			pf_conv_double(va_list *vl, t_pfs *pfs);
void			pf_conv_double_round_up(double *decimal);

/*
**	aux4.c		width control functions
*/
void			pf_ascii_width(t_pfs *pfs);
void			pf_ascii_width_comp(t_pfs *pfs);
void			pf_wchar_width(t_pfs *pfs);
void			pf_wchar_width_comp(t_pfs *pfs);
void			pf_width_init(t_pfs *pfs, int *width, int *n, int option);

/*
**	aux5.c		precision control functions
*/
void			pf_ascii_prec_init(t_pfs *pfs, int *width, int *n);
void			pf_ascii_prec(t_pfs *pfs);
void			pf_wchar_prec_init(t_pfs *pfs, int *width, int *n, int *i);
void			pf_wchar_prec(t_pfs *pfs);

/*
**	aux6.c		padding insert/append functions
*/
void			pf_as_pad_insert(char **dest, char *insert, int position);
void			pf_as_pad_append(char **dest, char *insert);
void			pf_wc_pad_insert(wchar_t **dest, wchar_t *insert, int position);
void			pf_wc_pad_append(wchar_t **dest, wchar_t *insert);

/*
**	aux7.c		display functions, alternate form handler & flag handler
*/
int				pf_ascii_display(t_pfs *pfs);
int				pf_wchar_display(t_pfs *pfs);
void			pf_sign_management(t_pfs *pfs);
void			pf_format_alternate(t_pfs *pfs);

#endif
