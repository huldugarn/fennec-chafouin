/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_options1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 15:53:59 by rle-corr          #+#    #+#             */
/*   Updated: 2016/05/17 14:20:40 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//	Initialiser la structure des options
void	o_init(t_opt **opt)
{
	*opt = (t_opt*)malloc(sizeof(t_opt));
	(*opt)->nata = 0;
	(*opt)->altf = 0;
	(*opt)->zpad = 0;
	(*opt)->bpad = 0;
	(*opt)->asig = 0;
	(*opt)->esig = 0;
	(*opt)->tsep = 0;
	(*opt)->mfwd = 0;
	(*opt)->prec = 0;
	(*opt)->lmod = 0;
	(*opt)->ctyp = '\0';
}
/* OLD
//	Attribuer aux options leurs valeurs
//	Retourne la taille totale des options
int			o_attr(const char * restrict format, int i, t_opt *opt)
{
	int		l;// taille de l'option
	int		L;// taille des options

	opt = o_init(opt);
	if ((l = o_nata(&((char *) format)[i])) > 0)
		opt->nata = ft_atoi(ft_strsub(format, i, l));
	L = l + o_flag(&((char *) format)[i + l], opt, 0);
	if ((l = o_mfwd(&((char *) format)[i + L])) > 0)
		opt->mfwd = ft_atoi(ft_strsub(format, (i + L), l));
	L = L + l;
	if ((l = o_prec(&((char *) format)[i + L])) > 0)
		opt->prec = ft_atoi(ft_strsub(format, (i + L + 1), (l - 1)));
	L = L + l;
	if ((l = o_lmod(&((char *) format)[i + L])) > 0)
		opt->lmod = l;
//	printf("\n	Taille de l'option LMOD : [%i]", l);
	if (l != 0)
		(l > 20) ? (L = L + 2) : (L = L + 1);
	opt->ctyp = *ft_strsub(format, (i + L), 1);
//	o_disp(opt, 1, 0);//	DISPLAY
//	printf("\n	Taille totale des options : [%i]", L);
	printf("=== ATTRIBUTION - OK ===\n");
	return (L);
}*/

//	Attribuer aux options leurs valeurs
//	Retourne la taille totale des options
t_opt			*o_attr(char *segment, t_opt **opt)
{
	int		i;
	int		l;// taille de l'option
	int		L;// taille des options

	i = 1;
	o_init(opt);
	if ((l = o_nata(&((char *)segment)[i])) > 0)
		(*opt)->nata = ft_atoi(ft_strsub(segment, i, l));
	L = l + o_flag(&((char *)segment)[i + l], (*opt), 0);
	if ((l = o_mfwd(&((char *)segment)[i + L])) > 0)
		(*opt)->mfwd = ft_atoi(ft_strsub(segment, (i + L), l));
	L = L + l;
	if ((l = o_prec(&((char *) segment)[i + L])) > 0)
		(*opt)->prec = ft_atoi(ft_strsub(segment, (i + L + 1), (l - 1)));
	L = L + l;
	if ((l = o_lmod(&((char *) segment)[i + L])) > 0)
		(*opt)->lmod = l;
//	printf("\n	Taille de l'option LMOD : [%i]", l);
	if (l != 0)
		(l > 20) ? (L = L + 2) : (L = L + 1);
	(*opt)->ctyp = *ft_strsub(segment, (i + L), 1);
	o_disp((*opt), 1, 0);//	DISPLAY
//	printf("\n	Taille totale des options : [%i]", L);
//	printf("=== ATTRIBUTION - OK ===\n");
	return *(opt);
}

//	Display structure
void	o_disp(t_opt *opt, int fd, int tc)
{
	pfps(">	NATA [", fd, tc);
	pfpn(opt->nata, fd, 0);
	pfps("]\n>	ALTF [", fd, tc);
	pfps(opt->altf? "ACTIF] [       " : "     ] [INACTIF", fd, tc);
	pfps("]\n>	ZPAD [", fd, tc);
	pfps(opt->zpad? "ACTIF] [       " : "     ] [INACTIF", fd, tc);
	pfps("]\n>	BPAD [", fd, tc);
	pfps(opt->bpad? "ACTIF] [       " : "     ] [INACTIF", fd, tc);
	pfps("]\n>	ASIG [", fd, tc);
	pfps(opt->asig? "ACTIF] [       " : "     ] [INACTIF", fd, tc);
	pfps("]\n>	ESIG [", fd, tc);
	pfps(opt->esig? "ACTIF] [       " : "     ] [INACTIF", fd, tc);
	pfps("]\n>	TSEP [", fd, tc);
	pfps(opt->tsep? "ACTIF] [       " : "     ] [INACTIF", fd, tc);
	pfps("]\n>	MFWD [", fd, tc);
	pfpn(opt->mfwd, fd, 0);
	pfps("]\n>	PREC [", fd, tc);
	pfpn(opt->prec, fd, 0);
	pfps("]\n>	LMOD [", fd, tc);
	pfpn(opt->lmod, fd, 0);
	pfps("]\n>	CTYP [", fd, tc);
	pfpc(opt->ctyp, fd, tc);
	pfps("]\n", fd, tc);
}
