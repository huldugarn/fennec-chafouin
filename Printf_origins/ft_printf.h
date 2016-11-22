/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:55:58 by rle-corr          #+#    #+#             */
/*   Updated: 2016/08/16 17:20:15 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include "../Libft/libft.h"

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
**	main.c					| Core function
*/
int					ft_printf(const char * restrict format, ...);
void				ft_pf_exit(char *message);
t_list				*ft_pf_splist(char *s);
void				ft_put_elem(t_list *elem);
char				*ft_pf_concatenate(t_list *f_list);
int					ft_pf_write(char *string);
t_list				*ft_pf_formap(t_list *s_format, va_list vl);
char				*f_padd(char *s, t_opt *o, int l);
char				*f_prec(char *s, t_opt *o, int l);
char				*f_sign(char *s, t_opt *o);
char				*f_altf(char *s, t_opt *o);
char				**ft_pf_splist_tab(char *s);
char				**ft_pf_formap_tab(char **s_format, va_list vl);
char				*ft_pf_concatenate_tab(char **f_tab);
int					ft_printf_tab(const char * restrict format, ...);

/*
**	ft_printf_options1.c	| Options management
*/
void				o_init(t_opt **opt);
//int					o_attr(const char * restrict format, int i, t_opt *opt);
t_opt				*o_attr(char *segment, t_opt **opt);
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
void		lmod_l(void **arg, t_opt *o, va_list vl);
char		*c_c(t_opt *o, va_list vl);
char		*c_C(t_opt *o, va_list vl);
char		*c_s(t_opt *o, va_list vl);
char		*c_S(t_opt *o, va_list vl);
char		*c_di(t_opt *o, va_list vl);
char		*c_oux(t_opt *o, va_list vl);
char		*c_OUX(t_opt *o, va_list vl);
char						*c_pointer(t_opt *o, va_list vl);
//int					c_hub(const char * restrict f, int i, t_opt *o, va_list vl);
char				*c_hub(char *s, va_list vl);
char				*c_percent(t_opt *o, int l);


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
char 				*unicheck(wchar_t c);
char 				*unimask1(wchar_t c);
char 				*unimask2(wchar_t c);
char 				*unimask3(wchar_t c);
char 				*unimask4(wchar_t c);


#endif
