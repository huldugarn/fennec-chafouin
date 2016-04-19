/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_options1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 15:53:59 by rle-corr          #+#    #+#             */
/*   Updated: 2016/04/19 15:21:57 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//	Initialiser la structure des options
t_opt	*o_init(t_opt *opt)
{
	opt = (t_opt*)malloc(sizeof(t_opt));
	opt->nata = 0;
	opt->altf = 0;
	opt->zpad = 0;
	opt->bpad = 0;
	opt->asig = 0;
	opt->esig = 0;
	opt->tsep = 0;
	opt->mfwd = 0;
	opt->prec = 0;
	opt->lmod = "\0";
	opt->ctyp = '\0';
	return (opt);
}

//	Attribuer aux options leurs valeurs
//	Retourne la taille totale des options
int			o_attr(const char * restrict format, int i, t_opt *opt)
{
	int		l;// taille de l'option
	int		L;// taille des options

	opt = o_init(opt);
	if ((l = o_nata(&((char *) format)[i])) > 0)
		opt->nata = ft_atoi(ft_strsub(format, i, l));
//	printf("\n	Taille de l'option NATA : [%i]", l);
	L = l + o_flag(&((char *) format)[i + l], opt, 0);
//	printf("\n	Taille de l'option FLAG : [%i]", (L - l));
	if ((l = o_mfwd(&((char *) format)[i + L])) > 0)
		opt->mfwd = ft_atoi(ft_strsub(format, (i + L), l));
//	printf("\n	Taille de l'option MFWD : [%i]", l);
	L = L + l;
	if ((l = o_prec(&((char *) format)[i + L])) > 0)
		opt->prec = ft_atoi(ft_strsub(format, (i + L + 1), (l - 1)));
//	printf("\n	Taille de l'option PREC : [%i]", l);
	L = L + l;
	if ((l = o_lmod(&((char *) format)[i + L])) > 0)
		opt->lmod = ft_strsub(format, (i + L), l);
//	printf("\n	Taille de l'option LMOD : [%i]", l);
	L = L + l;
	opt->ctyp = *ft_strsub(format, (i + L), 1);
	o_disp(opt, 1, 0);//	DISPLAY
//	printf("\n	Taille totale des options : [%i]", L);
	return (L);
}

//	Display structure
void	o_disp(t_opt *opt, int fd, int tc)
{
	pfps(" \n>	NATA [", fd, tc);
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
	pfps(opt->lmod, fd, tc);
	pfps("]\n>	CTYP [", fd, tc);
	pfpc(opt->ctyp, fd, tc);
	pfps("]\n", fd, tc);
}
