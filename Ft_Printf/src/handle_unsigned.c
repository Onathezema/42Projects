/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:45:34 by winorth           #+#    #+#             */
/*   Updated: 2019/08/22 16:03:08 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static	void	ft_putnbrbp(uintmax_t nbr, char *base, t_arg *arg,
		unsigned nbr_len)
{
	if (arg->got_precision)
		ft_printf_widthpad(nbr_len, arg->precision, base[0]);
	if (nbr == 0 && arg->got_precision && arg->precision == 0)
		return ;
	else
		ft_putnbrbase(nbr, base);
}

ssize_t			ft_printfhandle_uint(uintmax_t nbr, t_arg *arg, char *base,
		char *prefix)
{
	unsigned int	nbr_len;
	int				nbrstrlen;

	if (arg->got_precision)
		arg->pad_zeroes = 0;
	nbr_len = ft_printf_nbrlen(nbr, base);
	if (arg->got_width && !arg->right_pad && arg->pad_zeroes)
	{
		if (arg->got_precision)
			arg->precision = ft_max(arg->width, arg->precision);
		else
			arg->precision = ft_max(arg->width, nbr_len);
		arg->got_precision = 1;
		arg->got_width = 0;
	}
	nbrstrlen = ft_printf_calcnbrstrlen(nbr, base, prefix, arg);
	if (arg->got_width && !arg->right_pad)
		ft_printf_widthpad(nbrstrlen, arg->width, ' ');
	if (arg->force_prefix && prefix != NULL && nbr != 0)
		ft_putstr(prefix);
	ft_putnbrbp(nbr, base, arg, nbr_len);
	if (arg->got_width && arg->right_pad)
		ft_printf_widthpad(nbrstrlen, arg->width, ' ');
	return (arg->got_width ? ft_max(nbrstrlen, arg->width) : nbrstrlen);
}

ssize_t			ft_printfhandle_unsigned(char **format, va_list *args,
		t_arg *arg)
{
	uintmax_t	nbr;

	(void)format;
	nbr = ft_printf_unsignedfromlength(args, arg);
	return (ft_printfhandle_uint(nbr, arg, "0123456789", NULL));
}
