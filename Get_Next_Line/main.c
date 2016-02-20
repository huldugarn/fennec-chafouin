#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>
#include "libft/libft.h"

int	main()
{
	int		fd;
	char	**line;
	int		i;
	char	*init;
	int		r;

	i = 1;
	init = "test";
	line = &init;
	if ((fd = open("test", O_RDONLY)) == -1)
		return (0);
	printf("A	fd[%i] - line[%s]\n", fd, *line);
	while ((r = get_next_line(fd, line)))
	{
		if (r == -1)
		{
			printf("error\n");
			return (1);
		}
		printf("%i - 	", i++);
		printf("%s", *line);
		printf("\n");
		if (i == 5)
			return (1);
	}
	printf("Z\n");
	return (1);
}
