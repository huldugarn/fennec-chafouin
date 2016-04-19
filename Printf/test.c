#include <stdio.h>
#include <wchar.h>
int	main()
{
	int		i = 42;
	char	a = 'a';
	wint_t	n = "ñ";

//	printf("# flag	:	%#i\n", i);
//	printf("0 flag	:	%05i test\n", i);
//	printf("- flag	:	%5i test\n", i);
//	printf("  flag	:	% i test\n", i);
//	printf("+ flag	:	%+05i test\n", i);
//	printf("' flag	:	%'i test\n", i);
	printf("c conversions : a->%c\n", a);
	printf("C conversions : a->%C\n", a);
	printf("c conversions : n->%c\n", n);
	printf("C conversions : n->%C\n", n);
//	printf("\n",);
//	printf("\n",);
//	printf("\n",);
//	printf("\n",);
	return (0);
}
