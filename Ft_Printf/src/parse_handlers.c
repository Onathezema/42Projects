/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:45:58 by winorth           #+#    #+#             */
/*   Updated: 2019/07/25 12:04:38 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_printfparse_flags(char **format, t_arg *arg)
{
	if (**format == '#' || **format == '0' || **format == '-' || **format == '+'
			|| **format == ' ')
	{
		if (**format == '#')
			arg->force_prefix = 1;
		else if (**format == '0')
			arg->pad_zeroes = 1;
		else if (**format == '-')
			arg->right_pad = 1;
		else if (**format == '+')
			arg->force_sign = 1;
		else if (**format == ' ')
			arg->blank_sign = 1;
		(*format)++;
		if (arg->right_pad)
			arg->pad_zeroes = 0;
		return (ft_printfparse_flags(format, arg));
	}
	else
		return (*format);
}

char	*ft_printfparse_width(char **format, va_list *list, t_arg *arg)
{
	int	got;

	arg->width = 0;
	while (**format == '*' || ft_isdigit(**format))
	{
		if (**format == '*')
		{
			(*format)++;
			got = va_arg(*list, int);
			if (got < 0)
				arg->right_pad = 1;
			arg->width = got < 0 ? -got : got;
			arg->got_width = 1;
		}
		if (ft_isdigit(**format))
		{
			arg->got_width = 1;
			arg->width = 0;
			while (ft_isdigit(**format))
				arg->width = arg->width * 10 + (*(*format)++ - '0');
		}
	}
	return (*format);
}

char	*ft_printfparse_precision(char **format, va_list *list, t_arg *arg)
{
	int	prec;

	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			(*format)++;
			if ((prec = va_arg(*list, int)) >= 0)
			{
				arg->got_precision = 1;
				arg->precision = prec;
			}
			return (*format);
		}
		else
		{
			while (ft_isdigit(**format))
				arg->precision = arg->precision * 10 + (*(*format)++ - '0');
			arg->got_precision = 1;
			return (*format);
		}
	}
	else
		return (*format);
}

char	*ft_printfparse_length(char **format, t_arg *arg)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		arg->length = hh;
		return (*format += 2);
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		arg->length = ll;
		return (*format += 2);
	}
	else if (**format == 'h' || **format == 'l' || **format == 'j' ||
			**format == 'z')
	{
		if (**format == 'h')
			arg->length = h;
		else if (**format == 'l')
			arg->length = l;
		else if (**format == 'j')
			arg->length = j;
		else if (**format == 'z')
			arg->length = z;
		return ((*format)++);
	}
	else
		return (*format);
}
