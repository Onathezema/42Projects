/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:54:50 by winorth           #+#    #+#             */
/*   Updated: 2019/04/09 09:47:59 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include "./libft/libft.h"

# define BUFF_SIZE 32

int		get_next_line(const int fd, char **line);

#endif
