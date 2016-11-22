#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include "ft_printf.h"

#define FORMAT "DEBUT >| %S + %p = %s |< FIN"
#define ARG1 L"testé"
#define ARG2 &a
#define ARG3 "test"

// clear && echo \*\*\* && gcc -Wall -Werror -Wextra -I. -L ../Libft -lft ft_printf.h main.c test.c aux1_split_format.c ft_printf_conversions1.c ft_printf_options1.c ft_printf_options2.c ft_printf_displays1.c ft_printf_displays2.c && ./a.out
int			main()
{
	int	a = 0;
	int b = 0;

	a = ft_printf(	FORMAT\
					, ARG1\
					, ARG2\
					, ARG3\
				);
	printf("	Total:%i\n", a);
	b = printf(		FORMAT\
					, ARG1\
					, ARG2\
					, ARG3\
				);
	printf("	Total:%i\n", b);
	return (0);
}
