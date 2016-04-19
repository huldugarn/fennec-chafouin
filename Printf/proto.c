#include "../Libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main()
{
	int r = 0;
	r = ft_printf("%33$#- +\'18.8hhs%i%c", "e", 666666, 'u');
	ft_putnbr(r);
	return(0);
}
