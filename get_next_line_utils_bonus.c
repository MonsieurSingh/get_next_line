//
//  get_next_line_utils.c
//  get_next_line
//
//  Created by Devjyot Singh on 11/3/2024.
//

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_ptr;
	const char	*src_ptr;
	
	if (!dst && !src)
		return (NULL);
	dst_ptr = dst;
	src_ptr = src;
	while (n-- > 0)
		*(dst_ptr++) = *(src_ptr++);
	return (dst);
}

void	*ft_realloc(void *ptr, size_t size1, size_t size2)
{
	void	*new_ptr;
	
	if (ptr == NULL)
		return (malloc(size2));
	if (size2 == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size2);
	if (!new_ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (new_ptr != NULL)
	{
		ft_memcpy(new_ptr, ptr, size1);
		free(ptr);
	}
	return (new_ptr);
}
