/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bho.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:44:20 by winorth           #+#    #+#             */
/*   Updated: 2019/07/31 12:18:55 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

ssize_t	ft_printfhandle_octal(char **format, va_list *args, t_arg *arg)
{
	uintmax_t	nbr;

	(void)format;
	nbr = ft_printf_unsignedfromlength(args, arg);
	if (arg->force_prefix && nbr == 0 && arg->got_precision &&
			arg->precision == 0)
	{
		if (arg->got_width && !arg->right_pad)
			ft_printf_widthpad(1, arg->width, arg->pad_zeroes ? '0'
					: ' ');
		ft_putstr("0");
		if (arg->got_width && arg->right_pad)
			ft_printf_widthpad(1, arg->width, ' ');
		return (arg->got_width ? ft_max(arg->width, 1) : 1);
	}
	else if (arg->force_prefix && nbr != 0)
	{
		arg->got_precision = 1;
		arg->precision = ft_max(arg->precision, ft_printf_nbrlen(nbr,
					"01234567") + 1);
	}
	return (ft_printfhandle_uint(nbr, arg, "01234567", NULL));
}

ssize_t	ft_printfhandle_hex(char **format, va_list *args, t_arg *arg)
{
	uintmax_t	nbr;

	nbr = ft_printf_unsignedfromlength(args, arg);
	if (**format == 'X')
		return (ft_printfhandle_uint(nbr, arg, "0123456789ABCDEF", "0X"));
	else
		return (ft_printfhandle_uint(nbr, arg, "0123456789abcdef", "0x"));
}

ssize_t	ft_printfhandle_binary(char **format, va_list *args, t_arg *arg)
{
	uintmax_t	nbr;

	(void)format;
	nbr = ft_printf_unsignedfromlength(args, arg);
	return (ft_printfhandle_uint(nbr, arg, "01", "0b"));
}
