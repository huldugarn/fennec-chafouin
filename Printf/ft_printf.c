/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:53:59 by rle-corr          #+#    #+#             */
/*   Updated: 2016/03/24 18:15:01 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//	Option 1 : Next argument to access
//	Fonction qui verifie s'il existe un argument [next arg] valide.
//	Renvoie la longueur de l'argument ou -1 si non valide.
int				o_nata(char *c)
{
	int			n;

	if (*c == '$')
		return 0;
	if (ft_isdigit(*c))
	{
		n = o_nata(c + 1);
		return ((n == -1) ? -1 : (n + 1));
	}
	return (-1);
}

//	Option 2 : Flags
//	Fonction qui vérifie s'il existe un ou plusieurs arguments [flags] valides.
int				o_flag(char *c, t_pf **opt)
{
	if (*c != '#' && *c != '0' && *c != '-' &&
		*c != ' ' && *c != '+' && *c != ''')
		return (0);
	o_flag(c + 1, opt);
	if (*c == ''')
		opt->tsep = 1;
	if (*c == '+')
	{
		opt->esig = 1;
		opt->asig = 0;
	}
	if (*c == ' ' && opt->esig == 0)
		opt->asig = 1;
	if (*c == '-')
	{
		opt->bpad = 1;
		opt->zpad = 0;
	}
	if (*c == '0' && opt->bpad == 0)
		opt->zpad = 1;
	if (*c == '#')
		opt->altf = 1;
	return (1);
}

//	Option 3 : Minimum Field Width
//	Vérifie si l'argument est present et renvoie sa longeur.
//	Renvoie la longueur de l'argument ou -1 si absent.
int				o_mfwd(char *c)
{
	int			i;

	i = 1;
	if (*c == '.')
		while (ft_isdigit(*(c + i)))
			i++;
	else
		return (-1);
	return (i - 1);
}

//	Option 4 : Length Modifier
//	Vérifie si un flag de taille est présent et renvoie son code, sinon 0.
int				o_lmod(char *c)
{
	if (*c == 'h')
		return ((*(c + 1) == 'h') ? 1 : 2);
	if (*c == 'l')
		return ((*(c + 1) == 'l') ? 4 : 3);
	if (*c == 'j')
		return (5);
	if (*c == 't')
		return (6);
	if (*c == 'z')
		return (7);
	if (*c == 'q')
		return (8);
	if (*c == 'L')
		return (9);
	return (0);
}

//	Argument requis : Conversion type
//	Vérifie la validité du type de conversion
//
//	ft_memnchr(str, n)
int				r_ctyp(char *c)
{
	if (c == 'c' || c == 'C' || c == 's' || c == 'S' || c == 'p' || c == 'n' ||
		c == 'd' || c == 'D' || c == 'u' || c == 'U' || c == 'i' || c == '%' ||
		c == 'o' || c == 'O' || c == 'x' || c == 'X' || c == 'a' || c == 'A' ||
		c == 'e' || c == 'E' || c == 'f' || c == 'F' || c == 'g' || c == 'G')
		return (1);
	return (0);
}

//fonction qui dit si le character est un flag
int				is_flag(char c)
{
	if (ft_isdigit(c))
		//check if following characters comply to [next arg] option format
}



//fonction qui parcours le format a partir de la position p pour associer chaque % a un élément de liste
t_list			list(t_list **blist, const char * restrict format, int p)
{
	t_list	*next;

	next = ft_lstnew("\0", 1);
	blist = next;
	while (format[p] != '\0')
	{
		if (format[p] == )
		p++;
	}
}

//	fonction qui initialise la structure "OPTIONS"
int				opt_ini(t_opt **opt)
{
	opt->nata == 0;
	opt->altf == 0;
	opt->zpad == 0;
	opt->bpad == 0;
	opt->asig == 0;
	opt->esig == 0;
	opt->tsep == 0;
	opt->mfwd == 0;
	opt->lmod == 0;
}

//	fonction principale
int				ft_printf(const char * restrict format, ...)
{
	int			n;		//	nombre de caractères imprimés
	va_list		vl;
	
	if (!format)
		return (-1);
	n = 0;
	va_start(vl, format);
	n = ft_core(format, vl, n)
	va_end(vl);
	return (n);
}

//	reacteur
int			ft_core(format, vl, n)
{
	t_arg	*o_list;

	o_list = lecture(format);
	return(ecriture(format, vl, o_list));
}

//	lecture
t_arg		*lecture(const char * restrict format, int	i)
{
	t_arg	*o_init;
	t_arg	**o_list;

	o_init = NULL;
	o_list = *o_init;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			i++;
		gestionnaire_d_options(format[i], o_list);
	}
	return (o_list);
}

//	écriture
int			ecriture(format, vl, o_list)
{

	return (nombre de caractères imprimés)
}
