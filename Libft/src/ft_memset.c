/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:50:30 by winorth           #+#    #+#             */
/*   Updated: 2019/10/15 15:42:17 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	s;
	size_t			i;

	ptr = (unsigned char *)b;
	s = (unsigned char)c;
	i = 0;
	while (i < len)
		ptr[i++] = s;
	return (b);
}
