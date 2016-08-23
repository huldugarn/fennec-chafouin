#include <stdio.h>
#include <locale.h>

int		main(void)
{
	setlocale(LC_ALL, "");
	printf("%S", L"ê é é");
	return (0);
}
