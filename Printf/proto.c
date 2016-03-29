#include "../Libft/libft.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_pf_putc(char c, int fd);
int	ft_pf_puts(char const *s, int fd);
int	ft_pf_putn(int n, int fd, int r);

int	conversion(const char * restrict format, va_list vl, int i)
{
	int		n;
	t_opt	*opt;
	t_opt	**p_opt;
	
	opt = opt_init(&opt);
	p_opt = *opt;

	opt_attr(p_opt, format, i);
	n = 0;
	if (format[i + 1] == '%')
		n = ft_pf_putc('%', 1);
	if (format[i + 1] == 'c')
		n = ft_pf_putc(va_arg(vl, int), 1);
	if (format[i + 1] == 'i' || format[i + 1] == 'd')
		n = ft_pf_putn(va_arg(vl, int), 1, 0);
	if (format[i + 1] == 's')
		n = ft_pf_puts(va_arg(vl, char*), 1);
	return (n);
}

//	Initialiser la structure des options
void	opt_init(t_opt **opt)
{
	opt->nata = 0;
	opt->altf = 0;
	opt->zpad = 0;
	opt->bpad = 0;
	opt->asig = 0;
	opt->esig = 0;
	opt->tsep = 0;
	opt->mfwd = 0;
	opt->prec = 0;
	opt->lmod = 0;
}

//	Attribuer aux options leurs valeurs
void	opt_attr(t_opt **p_opt, const char * restrict format, int i)
{
	int	l;

	if ((l = o_nata(format[i])) >= 0)
		p_opt->nata = ft_atoi(ft_strsub(format, i, l));
	o_flag(format[i + l], p_opt);
	if ((l = o))
}

//	Noyau de la fonction ft_printf
int	pf(const char * restrict format, ...)
{
	int		n;
	va_list	vl;
	int		i;

	n = 0;
	va_start(vl, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			n = n + conversion(format, vl, i);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			n++;
		}
		i++;
	}
	va_end(vl);
	return(n);
}

int	main()
{
	int r = 0;
	r = pf("test	:	%c\nsuivant	:	%i%%\nstring	:	%s.\n", 'U', 100, "argument");
	ft_putnbr(r);
	return(0);
}
