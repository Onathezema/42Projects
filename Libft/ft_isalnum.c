/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:25:26 by winorth           #+#    #+#             */
/*   Updated: 2019/03/09 14:51:44 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

int		ft_isalnum(int c)
{
	return ((ft_isalpha(c) == 1 || ft_isdigit(c) == 1) ? 1 : 0);
}
