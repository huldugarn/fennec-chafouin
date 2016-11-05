#include <stdio.h>
#include <stdlib.h>

// testing purposes
#include <unistd.h>

void	*ft_memset(void *b, int c, size_t len)
{
	while (len > 0)
	{
		len--;
		((char *)b)[len] = (unsigned char)c;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	s = ft_memset(s, 0, n);
}

void	*ft_memalloc(size_t size)
{
	size_t	*locus;

	if (size > 2147483647)
		return (NULL);
	locus = (void *)malloc(size);
	if (locus == NULL)
		return (NULL);
	ft_bzero(locus, size);
	return (locus);
}

char	*ft_strnew(size_t size)
{
	return ((char *)ft_memalloc(size + 1));
}

size_t	ft_strlen(const char *str)
{
	int		position;

	position = 0;
	while (str[position] != '\0')
	{
		position++;
	}
	return (position);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*s_join;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	s_join = ft_strnew(len);
	i = 0;
	j = 0;
	if (s_join)
	{
		while (s1[j] != '\0')
			s_join[i++] = s1[j++];
		j = 0;
		while (s2[j] != '\0')
			s_join[i++] = s2[j++];
		s_join[i] = '\0';
		return (s_join);
	}
	else
		return (NULL);
}

char					*ft_ullitoa_base(unsigned long long value, int base)
{
	char				*s;
	char				*c;
	int					l;
	unsigned long long	v;

	if (base < 2 || base > 16 || value == 0)
		return (value == 0 ? "0\0" : NULL);
	v = value;
	l = 1;
	while ((v /= base) != 0)
		++l;
	if (!(s = (char*)malloc(sizeof(char) * l + 1)))
		return (NULL);
	s[l--] = '\0';
	c = "0123456789ABCDEF\0";
	while (value != 0)
	{
		s[l] = c[value % base];
		value /= base;
		--l;
	}
	return (s);
}

char					*ft_llitoa_base(long long n, int base)
{
	unsigned long long	u_n;

	u_n = n < 0 ? n * -1 : n;
	if (n < 0 && base == 10)
		return(ft_strjoin("-\0", ft_ullitoa_base(u_n, base)));
	return (ft_ullitoa_base(u_n, base));
}

char					*ft_itoa_base(int n, int base)
{
	long long			lln;

	lln = n;
	return (ft_llitoa_base(n, base));
}

int	main()
{
	printf("test : %s\n", ft_itoa_base(2147483647, 16));
	return (0);
}