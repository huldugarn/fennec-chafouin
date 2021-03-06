/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:56:52 by rle-corr          #+#    #+#             */
/*   Updated: 2016/03/26 13:27:05 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

/*
**	Structures
*/
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
**	Memory operations 1 & 2
*/
void				ft_memdel(void **byte_adress);
void				*ft_memset(void *byte, int c, size_t length);
void				ft_bzero(void *byte, size_t length);
void				*ft_memalloc(size_t size);

void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
**	ASCII & UNICODE String(s) operations 1
*/
char				*ft_strnew(size_t size);
wchar_t				*ft_wstrnew(size_t size);
size_t				ft_strlen(const char *s);
size_t				ft_wchar_width(wchar_t wchar);
size_t				ft_wstrlen(const wchar_t *wstr);

char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcpy(char *dst, const char *src);
wchar_t				*ft_wstrncpy(wchar_t *cpy, const wchar_t *str, size_t n);
wchar_t				*ft_wstrcpy(wchar_t *cpy, const wchar_t *str);

char				*ft_strndup(const char *str, size_t n);
char				*ft_strdup(const char *str);
wchar_t				*ft_wstrndup(const wchar_t *wstr, size_t n);
wchar_t				*ft_wstrdup(const wchar_t *wstr);

char				*ft_strnjoin(char const *s1, char const *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
wchar_t				*ft_wstrnjoin(wchar_t const *wstr1, wchar_t const *wstr2,
								size_t n);
wchar_t				*ft_wstrjoin(wchar_t const *wstr1, wchar_t const *wstr2);

size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
wchar_t				*ft_wstrncat(wchar_t *dst, wchar_t *src, size_t n);
wchar_t				*ft_wstrcat(wchar_t *dst, wchar_t *src);

char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);

char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				**ft_strsplit(char const *s, char c);

char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));

void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_strfill(char *s, char c);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_atoi_base(const char *str, const char *base);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

int					ft_strnextc(unsigned int i, char const *s, char c);

void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
void				ft_putwstr_fd(wchar_t const *wstr, int fd);
void				ft_putwstr(wchar_t const *wstr);

void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);

/*
**	Character operations 1 & 2
*/
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);

int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putwchar_fd(wchar_t c, int fd);
void				ft_putwchar(wchar_t c);

/*
**	Integer(s) operations
*/
int					ft_absolu(int n);

long				ft_power(int n, int e);

int					ft_squareroot(int a);
int					ft_squareroot(int n);

char				*ft_itoa(int n);
char				*ft_itoa_base(int value, int base);
char				*ft_llitoa_base(long long n, int base);
char				*ft_ullitoa_base(unsigned long long value, int base);

void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);

/*
**	ft_unicode.c
*/
char				**ft_unicode(unsigned long long int n);
char				**ft_unimask2(char *b, int l);
char				**ft_unimask3(char *b, int l);
char				**ft_unimask4(char *b, int l);

/*
**	Mono-linked lists operations
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstpushback(t_list **list, t_list *new);
void				ft_lstpushback_voidreturn(t_list **alst, t_list *new);

#endif
