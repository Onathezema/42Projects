/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlength.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:08:46 by winorth           #+#    #+#             */
/*   Updated: 2019/02/25 19:18:40 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_wordlength(char const *s, int c)
{
	int	word;

	word = 0;
	while (*s == c)
		s++;
	while (*s != c && *s != '\0')
	{
		word++;
		s++;
	}
	return (word);
}
