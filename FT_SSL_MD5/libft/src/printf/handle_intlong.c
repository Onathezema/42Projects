/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_intlong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:44:37 by winorth           #+#    #+#             */
/*   Updated: 2019/07/29 18:18:43 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

ssize_t				ft_printfhandle_long(char **format, va_list *args,
		t_arg *arg)
{
	arg->length = 1;
	return (ft_printf_gethandler(ft_tolower(**format))(format, args, arg));
}

static	intmax_t	getsignedfromlength(va_list *args, t_arg *arg)
{
	intmax_t	nbr;

	nbr = va_arg(*args, intmax_t);
	if (arg->length == hh)
		nbr = (char)nbr;
	else if (arg->length == h)
		nbr = (short int)nbr;
	else if (arg->length == l)
		nbr = (long int)nbr;
	else if (arg->length == ll)
		nbr = (long long int)nbr;
	else if (arg->length == j)
		nbr = (intmax_t)nbr;
	else if (arg->length == z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

ssize_t				ft_printfhandle_int(char **format, va_list *args,
		t_arg *arg)
{
	intmax_t	nbr;
	char		*prefix;

	(void)format;
	if (arg->got_precision)
		arg->pad_zeroes = 0;
	nbr = getsignedfromlength(args, arg);
	if (nbr < 0 || arg->force_sign || arg->blank_sign)
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			prefix = "-";
		}
		else if (arg->force_sign)
			prefix = "+";
		else if (arg->blank_sign)
			prefix = " ";
		else
			prefix = "";
		return (ft_printf_forceprefix(nbr, "0123456789", arg, prefix));
	}
	else
		return (ft_printfhandle_uint(nbr, arg, "0123456789", NULL));
}
