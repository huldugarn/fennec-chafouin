#include "../Libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		o_nata(char *c);
int		o_flag(char *c, t_opt *opt, int return_value);
int		o_mfwd(char *c);
int		o_prec(char *c);
int		o_lmod(char *c);
int		ft_pf_putc(char c, int fd);
int		ft_pf_puts(char const *s, int fd);
int		ft_pf_putn(int n, int fd, int r);
void	opt_init(t_opt *opt);
int		opt_attr(t_opt *opt, const char * restrict format, int i);

int		conversion_hub(const char * restrict format, int i, va_list vl)
{
	int		return_value;

	return_value = 0;
	if (format[i] == '%')
		return_value = ft_pf_putc('%', 1);
	if (format[i] == 'c')
		return_value = ft_pf_putc(va_arg(vl, int), 1);
	if (format[i] == 'i' || format[i + 1] == 'd')
		return_value = ft_pf_putn(va_arg(vl, int), 1, 0);
	if (format[i] == 's')
		return_value = ft_pf_puts(va_arg(vl, char*), 1);
	return (return_value);
}

//	Initialiser la structure des options
void	ft_pf_opt_initialize(t_opt *opt)
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
}
//	Display structure
void	ft_pf_opt_display(t_opt *opt, int fd)
{
	ft_pf_puts(" \n> Contenu de la structure OPTIONS :", fd);
	ft_pf_puts(" \n>	NATA [", fd);
	ft_pf_putn(opt->nata, fd, 0);
	ft_pf_puts("]\n>	ALTF [", fd);
	ft_pf_puts(opt->altf? "ACTIF] [       " : "     ] [INACTIF", fd);
	ft_pf_puts("]\n>	ZPAD [", fd);
	ft_pf_puts(opt->zpad? "ACTIF] [       " : "     ] [INACTIF", fd);
	ft_pf_puts("]\n>	BPAD [", fd);
	ft_pf_puts(opt->bpad? "ACTIF] [       " : "     ] [INACTIF", fd);
	ft_pf_puts("]\n>	ASIG [", fd);
	ft_pf_puts(opt->asig? "ACTIF] [       " : "     ] [INACTIF", fd);
	ft_pf_puts("]\n>	ESIG [", fd);
	ft_pf_puts(opt->esig? "ACTIF] [       " : "     ] [INACTIF", fd);
	ft_pf_puts("]\n>	TSEP [", fd);
	ft_pf_puts(opt->tsep? "ACTIF] [       " : "     ] [INACTIF", fd);
	ft_pf_puts("]\n>	MFWD [", fd);
	ft_pf_putn(opt->mfwd, fd, 0);
	ft_pf_puts("]\n>	PREC [", fd);
	ft_pf_putn(opt->prec, fd, 0);
	ft_pf_puts("]\n>	LMOD [", fd);
	ft_pf_puts(opt->lmod, fd);
	ft_pf_puts("]\n", fd);
}

//	Attribuer aux options leurs valeurs
//	Retourne la taille totale des options
int			ft_pf_opt_attribute(const char * restrict format, int i)
{
	int		l;// taille de l'option
	int		L;// taille des options
	t_opt	*opt;

	opt = NULL;
	ft_pf_opt_initialize(opt);
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
//	pf_opt_display(opt, 1);//	DISPLAY
	L = L + l;
//	printf("\n	Taille totale des options : [%i]", L);
	return (L);
}

//	Noyau de la fonction ft_printf
int	pf(const char * restrict format, ...)
{
	int		return_value;
	va_list	vl;
	int		L;
	int		i;

	return_value = 0;
	va_start(vl, format);
	L = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			L = ft_pf_opt_attribute(format, (i + 1));
			i = i + L;
			return_value = return_value + conversion_hub(format, i, vl);
		}
		else
		{
			return_value = return_value + ft_pf_putc(format[i + L], 1);
		}
		i++;
	}
	va_end(vl);
	return(return_value);
}

int	main()
{
	int r = 0;
	r = pf("test	:	%33$#0- -+\'6.8hhc\n", 'U');
	ft_putnbr(r);
	return(0);
}
