//
//  get_next_line.h
//  get_next_line
//
//  Created by Devjyot Singh on 11/3/2024.
//

#ifndef get_next_line_h
#define get_next_line_h
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 128
#endif

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd);
void	*ft_realloc(void *ptr, size_t size1, size_t size2);

#endif /* get_next_line_h */
