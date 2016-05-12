#include <stdio.h>
#include <locale.h>
#include <wchar.h>
int			main()
{
	wint_t	wc;
	wchar_t	*ws;

	setlocale(LC_ALL, "en_US.UTF-8");

	wc = L'\u0FC7';
	ws = L"࿇ test";
	printf("%lc = [%u]\n", wc, (unsigned int)wc);
	printf("࿇ = [%u]\n", (unsigned int)(ws[0]));
	return (0);
}

int			putwc(wint_t wc)
{

	return(1);
}
