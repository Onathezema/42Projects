/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:35:17 by winorth           #+#    #+#             */
/*   Updated: 2019/09/08 18:49:32 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <sys/types.h>
# include <inttypes.h>
# include <stdint.h>
# include <wchar.h>

int					ft_dprintf(int fd, const char *format, ...);
int					ft_printf(const char *format, ...);

enum
{
	none,
	hh,
	h,
	l,
	ll,
	j,
	z
}					e_length;

typedef struct		s_arg
{
	int				force_prefix : 1;
	int				pad_zeroes : 1;
	int				right_pad : 1;
	int				force_sign : 1;
	int				blank_sign : 1;
	int				got_width : 1;
	int				got_precision : 1;
	int				floatprecision : 6;
	unsigned int	width;
	unsigned int	precision;
	unsigned int	length;
}					t_arg;

ssize_t				ft_printfhandle_escape(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printfhandle_str(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printfhandle_wstr(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printfhandle_ptr(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printfhandle_int(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printfhandle_long(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printfhandle_octal(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printfhandle_unsigned(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printfhandle_hex(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printfhandle_char(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printfhandle_wchar(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printfhandle_null(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printfhandle_binary(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printfhandle_float(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printfhandle_charswrit(char **format, va_list *args,
		t_arg *arg);
ssize_t				ft_printfhandle_uint(uintmax_t nbr, t_arg *arg, char
		*base, char *prefix);

typedef ssize_t		(*t_handler)(char **, va_list *, t_arg *);

t_handler			ft_printf_gethandler(char c);

char				*ft_printfparse_flags(char **format, t_arg *arg);
char				*ft_printfparse_width(char **format, va_list *list,
		t_arg *arg);
char				*ft_printfparse_precision(char **format, va_list *list,
		t_arg *arg);
char				*ft_printfparse_length(char **format, t_arg *arg);

uintmax_t			ft_printf_unsignedfromlength(va_list *args, t_arg *arg);
void				ft_printf_widthpad(int nbrstrlen, int width,
		char padwith);
unsigned int		ft_printf_nbrlen(uintmax_t nbr, char *base);
unsigned int		ft_printf_calcnbrstrlen(uintmax_t nbr, char *base,
		char *prefix, t_arg *arg);
ssize_t				ft_printf_forceprefix(uintmax_t nbr, char *base,
		t_arg *arg, char *prefix);

#endif
