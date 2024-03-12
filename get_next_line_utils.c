//
//  get_next_line_utils.c
//  get_next_line
//
//  Created by Devjyot Singh on 11/3/2024.
//

#include "get_next_line.h"
/*
char	*ft_strchr(const char *s, int c)
{
	const char		*ptr;
	unsigned char	uc;

	ptr = s;
	uc = (unsigned char)c;
	while (*ptr || *ptr == uc)
	{
		if (*ptr == uc)
			return ((char *)ptr);
		ptr++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strnlen(const char *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t maxlen)
{
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strnlen(dst, maxlen);
	if (dstlen == maxlen)
		return (maxlen + srclen);
	if (srclen < maxlen - dstlen)
		ft_memcpy(dst + dstlen, src, srclen + 1);
	else
	{
		ft_memcpy(dst + dstlen, src, (maxlen - dstlen) - 1);
		dst[maxlen - 1] = '\0';
	}
	return (dstlen + srclen);
}*/

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

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	
	if (ptr == NULL)
		return (malloc(size));
	if (!size)
		return (ptr);
	new_ptr = malloc(size);
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
