/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_strs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:45:43 by winorth           #+#    #+#             */
/*   Updated: 2019/08/27 12:40:31 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static	size_t	calc_wstrlen(wchar_t *str, int precision, size_t i)
{
	if (*str == '\0' || precision == 0)
		return (i);
	else if (*str <= 0x7F)
		return (calc_wstrlen(str + 1, precision - 1, i + 1));
	else if (*str <= 0x7FF && precision >= 2)
		return (calc_wstrlen(str + 1, precision - 2, i + 2));
	else if (*str <= 0xFFFF && precision >= 3)
		return (calc_wstrlen(str + 1, precision - 3, i + 3));
	else if (*str <= 0x10FFFF && precision >= 4)
		return (calc_wstrlen(str + 1, precision - 4, i + 4));
	else
		return (i);
}

static	size_t	ft_wstrlen(wchar_t *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		str++;
	}
	return (i);
}

ssize_t			ft_printfhandle_wstr(char **format, va_list *args,
		t_arg *arg)
{
	wchar_t	*str;
	int		strlen;

	(void)format;
	(void)arg;
	str = va_arg(*args, wchar_t*);
	if (str == NULL)
		str = L"(null)";
	strlen = arg->got_precision ? calc_wstrlen(str, arg->precision, 0) :
		ft_wstrlen(str);
	if (arg->got_width && !arg->right_pad)
		ft_printf_widthpad(strlen, arg->width, arg->pad_zeroes ? '0' :
				' ');
	ft_putnwstr(str, strlen);
	if (arg->got_width && arg->right_pad)
		ft_printf_widthpad(strlen, arg->width, ' ');
	return (arg->got_width ? ft_max(strlen, arg->width) : strlen);
}

ssize_t			ft_printfhandle_str(char **format, va_list *args,
		t_arg *arg)
{
	char	*str;
	int		strlen;

	if (arg->length == 1)
		return (ft_printfhandle_wstr(format, args, arg));
	else
	{
		str = va_arg(*args, char*);
		if (str == NULL)
			str = "(null)";
		strlen = arg->got_precision ? ft_nstrlen(str, arg->precision) :
			ft_strlen(str);
		if (arg->got_width && !arg->right_pad)
			ft_printf_widthpad(strlen, arg->width, arg->pad_zeroes ?
					'0' : ' ');
		ft_putnstr(str, strlen);
		if (arg->got_width && arg->right_pad)
			ft_printf_widthpad(strlen, arg->width, ' ');
		return (arg->got_width ? ft_max(strlen, arg->width) : strlen);
	}
}
