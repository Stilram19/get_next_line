#include "get_next_line.h"
#include <fcntl.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDWR, 0666);
	while ((line = get_next_line(fd)))
	{
		ft_putstr(line);
		free(line);
	}
	system("leaks a.out");
	return (0);
}
