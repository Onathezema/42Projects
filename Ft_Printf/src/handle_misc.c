/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_misc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:43:28 by winorth           #+#    #+#             */
/*   Updated: 2019/08/19 19:03:38 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

ssize_t	ft_printfhandle_null(char **format, va_list *args, t_arg *arg)
{
	(void)args;
	if (arg->got_width && !arg->right_pad)
		ft_printf_widthpad(1, arg->width, arg->pad_zeroes ? '0' : ' ');
	ft_putchar(**format);
	if (arg->got_width && arg->right_pad)
		ft_printf_widthpad(1, arg->width, ' ');
	return (arg->got_width ? ft_max(arg->width, 1) : 1);
}

ssize_t	ft_printfhandle_escape(char **format, va_list *args, t_arg *arg)
{
	(void)format;
	(void)args;
	(void)arg;
	if (arg->got_width && !arg->right_pad)
		ft_printf_widthpad(1, arg->width, arg->pad_zeroes ? '0' : ' ');
	ft_putchar('%');
	if (arg->got_width && arg->right_pad)
		ft_printf_widthpad(1, arg->width, ' ');
	return (arg->got_width ? ft_max(arg->width, 1) : 1);
}

ssize_t	ft_printfhandle_float(char **format, va_list *args, t_arg *arg)
{
	double	nbr;
	char	*str;

	(void)format;
	nbr = va_arg(*args, double);
	if (arg->floatprecision == 0)
		arg->floatprecision = 6;
	str = ft_ftoa(nbr, arg->floatprecision);
	ft_putstr(str);
	return (*str);
}

ssize_t	ft_printfhandle_ptr(char **format, va_list *args, t_arg *arg)
{
	char		*base;
	uintmax_t	nbr;

	(void)format;
	arg->length = z;
	if (arg->got_precision)
		arg->pad_zeroes = 0;
	base = "0123456789abcdef";
	nbr = ft_printf_unsignedfromlength(args, arg);
	return (ft_printf_forceprefix(nbr, base, arg, "0x"));
}
