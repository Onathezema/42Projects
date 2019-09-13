/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapnfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:50:34 by winorth           #+#    #+#             */
/*   Updated: 2019/08/29 14:50:37 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_swapnfree(char *new, char **old)
{
	char *temp;

	temp = NULL;
	if (old && *old)
		temp = *old;
	if (new != temp && temp)
		free(temp);
	return (new);
}
