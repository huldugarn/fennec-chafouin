#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int		fd;
	char	**line;

	line = NULL;
	if ((fd = open("test", O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, line))
		printf("");
//	printf("O\n");
	return (1);
}
