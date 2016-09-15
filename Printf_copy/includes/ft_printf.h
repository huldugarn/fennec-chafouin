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
# include <locale.h>
# include <wchar.h>
# include "./libft/libft.h"
# define CTYP "\%aAcCdDeEfFgGinoOpsSuUxX"

/*
**	Structures
*/

typedef struct		s_opt
{
	int				nata;
	int				altf;
	int				zpad;
	int				bpad;
	int				asig;
	int				esig;
	int				tsep;
	int				mfwd;
	int				prec;
	int				lmod;
	char			ctyp;
}					t_opt;

/*
**	Core functions						|	main.c
*/
int					ft_printf(const char *restrict format, ...);
void				ft_pf_exit(char *message);
t_list				*ft_pf_splist(char *s, int i);
t_list				*ft_pf_formap(t_list *s_format, va_list vl);
char				*ft_pf_concatenate(t_list *f_list);

/*
**	Options and type casts management	|	aux0_options_management.c
*/
void				o_init(t_opt **opt);
t_opt				*o_attr(char *segment, t_opt **opt);
void				o_disp(t_opt *opt);
long long			type_cast_signed(t_opt *o, va_list vl);
unsigned long long	type_cast_unsigned(t_opt *o, va_list vl);
/*
**	Options lengths						|	aux1_options_lengths.c
*/
int					o_nata(char *c);
int					o_flag(char *c, t_opt *opt, int return_value);
int					o_mfwd(char *c);
int					o_prec(char *c);
int					o_lmod(char *c);

/*
**	Conversions hub & format functions	|	aux2_conversions_hub.c
*/
char				*c_hub(va_list vl, t_opt *o);
char				*f_padd(char *s, t_opt *o, int l);
char				*f_prec(char *s, t_opt *o, int l);
char				*f_sign(char *s, t_opt *o);
char				*f_altf(char *s, t_opt *o);
/*
**	Characters & Strings Conversions	|	aux3_conversions_alpha.c
*/
char				*c_percent(t_opt *o, int l);
char				*c_c(t_opt *o, va_list vl);
char				*c_c_l(t_opt *o, va_list vl);
char				*c_s(t_opt *o, va_list vl);
char				*c_s_l(t_opt *o, va_list vl);
/*
**	Numbers Conversions					|	aux4_conversions_num.c
*/
char				*c_di(t_opt *o, va_list vl);
char				*c_oux(t_opt *o, va_list vl);
char				*c_oux_l(t_opt *o, va_list vl);
char				*c_pointer(t_opt *o, va_list vl);

/*
**	Wide chars							|	aux5_unicode.c
*/
char				*unicheck(wchar_t c);
char				*unimask1(wchar_t c);
char				*unimask2(wchar_t c);
char				*unimask3(wchar_t c);
char				*unimask4(wchar_t c);

#endif
