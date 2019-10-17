/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:25:35 by winorth           #+#    #+#             */
/*   Updated: 2019/10/10 17:06:53 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 32

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <wchar.h>
# include <sys/types.h>
# include <inttypes.h>
# include <stdint.h>
# include <string.h>

# ifndef FALSE
#  define FALSE 0
# endif
# ifndef TRUE
#  define TRUE !FALSE
# endif

# define IS_UPPER(c)	((unsigned int)(c - 'A') < 26)
# define IS_LOWER(c)	((unsigned int)(c - 'a') < 26)
# define TO_UPPER(c)	(IS_LOWER(c) ? c - ' ' : c)
# define TO_LOWER(c)	(IS_UPPER(c) ? c + ' ' : c)

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					get_next_line(const int fd, char **line);
int					ft_min(int x, int y);
int					ft_max(int x, int y);
void				ft_putnbrbase_fd(uintmax_t nbr, char *base, int fd);
void				ft_putnbrbase(uintmax_t nbr, char *base);
void				ft_putwchar(wchar_t chr);
void				ft_putwchar_fd(wchar_t chr, int fd);
void				ft_putwstr(wchar_t const *str);
void				ft_putwstr_fd(wchar_t const *str, int fd);
void				ft_putnstr(char const *str, size_t str_len);
void				ft_putnstr_fd(char const *str, size_t str_len, int fd);
void				ft_putnwstr(const wchar_t *str, size_t len);
size_t				ft_nstrlen(const char *str, size_t maxlen);
char				*ft_utoa(unsigned int nbr, char const *base_chr);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle, \
		size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(intmax_t n);
void				ft_putchar(unsigned char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_iswhitespaces(char c);
int					ft_isstrwhitespaces(char c);
int					ft_isotherwhitespaces(char c);
char				*ft_strndup(const char *s, size_t n);
int					ft_wordcount(const char *s, char c);
size_t				ft_wordlength(char const *s, int c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstlink(t_list **alst, t_list *new);
int					ft_lstadd(t_list **alst, void *content,
		size_t content_size);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstrev(t_list **alst);
void				ft_strrev(char *s);
void				*ft_realloc(void *ptr, size_t old, size_t new_size);
char				*ft_ftoa(long double n, size_t prec);
char				*ft_strmerge(char *a, char *b);
char				*ft_swapnfree(char *new, char **old);
int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
int					numlength(long long num);

char				*ft_stpcpy(char *s1, const char *s2);
char				*ft_stpncpy(char *s1, const char *s2, size_t n);
char				*ft_strupcase(char *str);
#endif
