//
//  get_next_line.c
//  get_next_line
//
//  Created by Devjyot Singh on 11/3/2024.
//

#include "get_next_line_bonus.h"

char	*init(void)
{
	return ((char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)));
}

int		byte_read(int fd, char *c, int *bytes_read)
{
	*bytes_read = (int)(read(fd, c, sizeof(char)));
	return (*bytes_read);
}

char	*read_line(int fd, char *line)
{
	int		i;
	char	c;
	int	bytes_read;
	
	i = 0;
	while (byte_read(fd, &c, &bytes_read) > 0)
	{
		line[i++] = c;
		if (i >= BUFFER_SIZE)
		{
			line = ft_realloc(line, i, i * 2);
			if (!line)
				return (NULL);
		}
		if (c == '\n')
			break ;
	}
	if (bytes_read < 0 || (bytes_read == 0 && i == 0))
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = init();
	if (!line)
		return (NULL);
	line = read_line(fd, line);
	return (line);
}
