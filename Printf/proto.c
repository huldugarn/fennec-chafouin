#include "../Libft/libft.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_pf_putc(char c, int fd);
int	ft_pf_puts(char const *s, int fd);
int	ft_pf_putn(int n, int fd, int r);

int	conversion(const char * restrict format, va_list vl, int i)
{
	int	n;

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
	int k = 0;
	wchar_t	test = 220;
	r = pf("test	:	%c\nsuivant	:	%i%%\nstring	:	%s.\n", 'U', 100, "argument");
	ft_putnbr(r);
	ft_pf_putc('\n', 1);
	while (ft_power(2, k++) < test);
	k = k / 8;
	write(1, &test, k);
	ft_pf_putc('\n', 1);
//	ft_putchar_uni((wchar_t)255, 1);
	ft_pf_putc('\n', 1);
	return(0);
}
