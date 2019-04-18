/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:02:44 by winorth           #+#    #+#             */
/*   Updated: 2019/04/18 12:29:37 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     check_conn(char *str)
{
    int block;
    int i;

    block = 0;
    i = 0;
    while (i < 20)
    {
        if (str[i] == '#')
        {
            if ((i + 1) < 20 && str[i + 1] == '#')
                block++;
            if ((i - 1) >= 0 && str[i - 1] == '#')
                block++;
            if ((i + 5) < 20 && str[i + 5] == '#')
                block++;
            if ((i - 5) >= 0 && str[i - 5] == '#')
                block++;
        }
        i++;
    }
    return (block == 6 || block == 8);
}