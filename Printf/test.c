#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include "ft_printf.h"

int			main()
{
//	wint_t	wc;
//	wchar_t	*ws;

	setlocale(LC_ALL, "en_US.UTF-8");

//	wc = L'\u0FC7';
//	ws = L"࿇ test";
//	printf("%lc = [%u]\n", wc, (unsigned int)wc);
//	printf("࿇ = [%u]\n", (unsigned int)(ws[0]));
	printf("test yo : [%5%]\n");

	t_list	*list;
	list = ft_pf_splist("\%kkkkg test \%mmmma suite \%hhh#d fin\0");
//	ft_putendl("OK1");
	ft_lstiter(list, ft_put_elem);
	ft_putendl(ft_pf_concatenate(list));
	return (0);
}
