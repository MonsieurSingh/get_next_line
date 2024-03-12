//
//  get_next_line.c
//  get_next_line
//
//  Created by Devjyot Singh on 11/3/2024.
//

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	c;
	int		i;
	int		bytes_read;
	int		b_size;
	char	*temp;

	b_size = BUFFER_SIZE;
//	printf("Buffer size: %d\n", b_size);
	if (fd < 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (b_size + 1));
	if (!line)
		return (NULL);
	i = 0;
	while ((bytes_read = (int)read(fd, &c, 1)) > 0)
	{
		if (i >= b_size)
		{
			b_size *= 2;
//			printf("New buffer size: %d\n", b_size);
			temp = ft_realloc(line, b_size + 1);
			if (!temp)
			{
				free(temp);
				return (NULL);
			}
//			free(line);
			line = temp;
		}
		if (c == '\n')
		{
			line[i] = '\n';
			line[++i] = '\0';
			break ;
		}

//		printf("%c", c);
		line[i++] = c;
	}
	if (bytes_read < 0 || (bytes_read == 0 && i == 0))
	{
		free(line);
		return (NULL);
	}
	return (line);
}
