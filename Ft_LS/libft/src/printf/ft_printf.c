/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:42:16 by winorth           #+#    #+#             */
/*   Updated: 2019/09/06 20:23:01 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static ssize_t	handle_arg(char **format, va_list *args, t_arg *sarg)
{
	ssize_t		res;
	t_handler	handler;

	if ((*(++*format)) == '\0')
		return (0);
	if ((ft_printfparse_flags(format, sarg)) == NULL)
		return (-1);
	if ((ft_printfparse_width(format, args, sarg)) == NULL)
		return (-1);
	if ((ft_printfparse_precision(format, args, sarg)) == NULL)
		return (-1);
	if ((ft_printfparse_length(format, sarg)) == NULL)
		return (-1);
	if (**format == '\0')
		return (0);
	if (ft_printf_gethandler(**format) == NULL)
		handler = ft_printfhandle_null;
	else
		handler = ft_printf_gethandler(**format);
	res = handler(format, args, sarg);
	(*format)++;
	return (res);
}

static int		ft_inside_printf(const char *format, va_list *args,
		size_t chars)
{
	char	*next_arg;
	t_arg	sarg;
	ssize_t handler_len;

	next_arg = ft_strchr(format, '%');
	if (*format == '\0')
		return (chars);
	if (next_arg == NULL)
	{
		ft_putstr(format);
		return (chars + ft_strlen(format));
	}
	else if (next_arg > format)
	{
		ft_putnstr(format, next_arg - format);
		return (ft_inside_printf(next_arg, args, chars + (next_arg - format)));
	}
	else
	{
		ft_bzero(&sarg, sizeof(sarg));
		if ((handler_len = handle_arg((char **)&format, args, &sarg)) == -1)
			return (-1);
		else
			return (ft_inside_printf(format, args, chars + handler_len));
	}
}

int				ft_dprintf(int fd, const char *format, ...)
{
	va_list args;
	int		res;

	va_start(args, format);
	res = ft_inside_printf(format, &args, fd);
	va_end(args);
	return (res);
}

int				ft_printf(const char *format, ...)
{
	va_list args;
	int		res;

	va_start(args, format);
	res = ft_inside_printf(format, &args, 0);
	va_end(args);
	return (res);
}
