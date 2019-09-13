/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:43:51 by winorth           #+#    #+#             */
/*   Updated: 2019/09/04 20:37:59 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	print_one(char *file, int flags)
{
	t_dips	*files;

	files = newdir(file, "", flags);
	plist(files);
	free(files);
}
