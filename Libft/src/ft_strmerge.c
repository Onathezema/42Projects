/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 12:39:34 by winorth           #+#    #+#             */
/*   Updated: 2019/08/27 12:39:36 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmerge(char *a, char *b)
{
	char	*res;

	res = ft_strjoin(a, b);
	ft_strdel(&a);
	ft_strdel(&b);
	return (res);
}
