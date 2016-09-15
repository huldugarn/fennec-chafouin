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
//	wint_t	wc;
//	wchar_t	*ws;

//	setlocale(LC_ALL, "en_US.UTF-8");

//	wc = L'\u0FC7';
//	ws = L"࿇ test";
//	printf("%lc = [%u]\n", wc, (unsigned int)wc);
//	printf("࿇ = [%u]\n", (unsigned int)(ws[0]));

//	t_list	*list;
//	list = ft_pf_splist("\%kkkkg test \%mmmma suite \%hhh#d fin\0");
//	ft_putendl("OK1");s
//	ft_lstiter(list, ft_put_elem);
//	ft_putendl(ft_pf_concatenate(list));

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
