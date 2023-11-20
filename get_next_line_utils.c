#include "get_next_line.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t i;
    size_t aux;
    i = 0;
    aux = dstsize - 1;
    if (dstsize == 0)
        return ft_strlen(src);
    else if (dstsize <= ft_strlen(src)){
        while(aux--){
            dst[i] = src[i];
            i ++;
        }
        dst[i] = '\0';
    }
    else if (dstsize > ft_strlen(src)){
        while(src[i] != '\0'){
            dst[i] = src[i];
            i ++;
        }
        dst[i] = '\0';
    }
    return ft_strlen(src);
}

void ft_bzero(void *s, size_t n)
{
    size_t i;
    unsigned char * c;

    c = (unsigned char * )s;

    i = 0;

    while(i < n){
        c[i] = '\0';
        i ++;
    }
}

unsigned long ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (!*str++)
			return (NULL);
	}
	return ((char *)str);
}

void *ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	n;

	n = ft_strlen(s);
	ptr = (char *)malloc(n + 1 * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s, n + 1);
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	size;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (size + 1));
	i = 0;
	if (!str)
		return (NULL);
	while (*s1)
	{
		str[i++] = *s1;
		++s1;
	}
	while (*s2)
	{
		str[i++] = *s2;
		++s2;
	}
	str[i] = '\0';
	return (str);
}