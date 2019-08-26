/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:45:00 by winorth           #+#    #+#             */
/*   Updated: 2019/08/22 16:02:57 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

ssize_t	ft_printfhandle_charswrit(char **format, va_list *args, t_arg *arg)
{
	(void)format;
	(void)args;
	(void)arg;
	return (0);
}

ssize_t	ft_printfhandle_wchar(char **format, va_list *args, t_arg *arg)
{
	wchar_t		chr;
	int			chr_len;

	(void)format;
	chr = (wchar_t)va_arg(*args, wint_t);
	if (chr <= 0x7F)
		chr_len = 1;
	else if (chr <= 0x7FF)
		chr_len = 2;
	else if (chr <= 0xFFFF)
		chr_len = 3;
	else if (chr <= 0x10FFFF)
		chr_len = 4;
	else
		chr_len = 0;
	if (arg->got_width && !arg->right_pad)
		ft_printf_widthpad(chr_len, arg->width, arg->pad_zeroes ? '0' : ' ');
	ft_putwchar(chr);
	if (arg->got_width && arg->right_pad)
		ft_printf_widthpad(chr_len, arg->width, arg->pad_zeroes ? '0' : ' ');
	return (arg->got_width ? ft_max(chr_len, arg->width) : chr_len);
}

ssize_t	ft_printfhandle_char(char **format, va_list *args, t_arg *arg)
{
	(void)format;
	if (arg->length == 1)
		return (ft_printfhandle_wchar(format, args, arg));
	else
	{
		if (arg->got_width && !arg->right_pad)
			ft_printf_widthpad(1, arg->width, arg->pad_zeroes ? '0' : ' ');
		ft_putchar(va_arg(*args, int));
		if (arg->got_width && arg->right_pad)
			ft_printf_widthpad(1, arg->width, ' ');
		return (arg->got_width ? ft_max(arg->width, 1) : 1);
	}
}
