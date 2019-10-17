/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 18:22:00 by winorth           #+#    #+#             */
/*   Updated: 2019/07/29 18:22:06 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbrbase(uintmax_t nbr, char *base)
{
	ft_putnbrbase_fd(nbr, base, STDOUT_FILENO);
}
