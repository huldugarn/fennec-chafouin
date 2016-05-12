/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:55:58 by rle-corr          #+#    #+#             */
/*   Updated: 2016/05/12 13:51:30 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
/*
**							| Structures
*/
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
	int				prec;	//	precision
	int				lmod;	//	length modifier
	char			ctyp;	//	conversion type
}					t_opt;

typedef struct		s_arg
{
	int				i;		//	argument numéro i
	char			type;	//	type de conversion
	t_opt			opt;	//	options & attributs
}					t_arg;

/*
**	ft_printf.c				| Core function
*/
void				va_end(va_list vl);
//	void				va_start(va_list vl, last);
//	type				va_arg(va_list vl, type);
int					ft_printf(const char * restrict format, ...);

/*
**	ft_printf_options1.c	| Options management
*/
t_opt				*o_init(t_opt *opt);
int					o_attr(const char * restrict format, int i, t_opt *opt);
void				o_disp(t_opt *opt, int fd, int tc);

/*
**	ft_printf_options2.c	| Options lengths
*/
int					o_nata(char *c);
int					o_flag(char *c, t_opt *opt, int return_value);
int					o_mfwd(char *c);
int					o_prec(char *c);
int					o_lmod(char *c);

/*
**	ft_printf_conversions1.c| Conversions
*/
char				c_type(char *c);
int					c_hub(const char * restrict f, int i, t_opt *o, va_list vl);

/*
**	ft_printf_conversions2.c| Characters & Strings Conversions
*/
int					c_char(va_list vl, t_opt *o, int tc);
int					c_str_s(va_list vl, t_opt *o, int tc);
int					c_str_l(va_list vl, t_opt *o, int tc);

/*
**	ft_printf_conversions3.c| Numbers Conversions
*/


/*
**	ft_printf_displays1.c	| Tools
*/
int					pfpc(char c, int fd, int tc);
int					pfps(const char *c, int fd, int tc);
int					pfpn(int n, int fd, int r);

/*
**	ft_printf_displays2.c	| Wide char
*/
int					wwc(int fd, void *caa, int cas);
int					umm(int fd, wint_t wc);
int					um2(int fd, char ca[4], wint_t wc);
int					um3(int fd, char ca[4], wint_t wc);
int					um4(int fd, char ca[4], wint_t wc);

#endif
