/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:02:27 by winorth           #+#    #+#             */
/*   Updated: 2019/07/29 18:25:15 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstadd(t_list **alst, void *content, size_t content_size)
{
	t_list	*new;

	if ((new = ft_lstnew(content, content_size)) == NULL)
		return (0);
	ft_lstlink(alst, new);
	return (1);
}
