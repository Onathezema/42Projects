/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:36:45 by winorth           #+#    #+#             */
/*   Updated: 2019/05/31 14:37:18 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				ft_putstr(char const *s);
void				ft_memdel(void **ap);
void				ft_putchar(char c);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
char				*ft_strncpy(char *dst, const char *src, size_t n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstrev(t_list **alst);
t_list				*ft_lstnew(void const *content, size_t content_size);
size_t				ft_lstcount(t_list *lst);
void				ft_strclr(char *s);
size_t				ft_strlen(char *str);
#endif
