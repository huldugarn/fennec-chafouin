#include "../Libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main()
{
	int r = 0;
	r = ft_printf("test : [%33$#0- -+\'6.8hhs]_\n", "exemple");
	ft_putnbr(r);
	return(0);
}
