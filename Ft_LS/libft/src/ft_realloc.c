/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:30:29 by winorth           #+#    #+#             */
/*   Updated: 2019/08/19 16:33:18 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_realloc(void *ptr, size_t old, size_t new_size)
{
	void	*new;

	if (ptr == NULL)
		return (malloc(new_size));
	if (!(new = ft_memalloc(new_size)))
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(new, ptr, (old < new_size) ? old : new_size);
	free(ptr);
	return (new);
}
