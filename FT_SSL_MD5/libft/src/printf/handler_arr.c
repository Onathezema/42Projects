/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:45:14 by winorth           #+#    #+#             */
/*   Updated: 2019/07/31 14:09:19 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static	void	setup_arr(t_handler *handlers)
{
	handlers['c'] = &ft_printfhandle_char;
	handlers['C'] = &ft_printfhandle_wchar;
	handlers['s'] = &ft_printfhandle_str;
	handlers['S'] = &ft_printfhandle_wstr;
	handlers['x'] = &ft_printfhandle_hex;
	handlers['X'] = &ft_printfhandle_hex;
	handlers['p'] = &ft_printfhandle_ptr;
	handlers['d'] = &ft_printfhandle_int;
	handlers['i'] = &ft_printfhandle_int;
	handlers['D'] = &ft_printfhandle_long;
	handlers['o'] = &ft_printfhandle_octal;
	handlers['O'] = &ft_printfhandle_long;
	handlers['u'] = &ft_printfhandle_unsigned;
	handlers['U'] = &ft_printfhandle_long;
	handlers['b'] = &ft_printfhandle_binary;
	handlers['f'] = &ft_printfhandle_float;
	handlers['n'] = &ft_printfhandle_charswrit;
	handlers['%'] = &ft_printfhandle_escape;
}

t_handler		ft_printf_gethandler(char c)
{
	static t_handler	*handlers;

	handlers = NULL;
	if (handlers == NULL)
	{
		handlers = ft_memalloc(sizeof(*handlers) * 256);
		if (handlers != NULL)
			setup_arr(handlers);
	}
	free(handlers);
	return (handlers[(int)c]);
}
