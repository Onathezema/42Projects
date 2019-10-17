/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:10:17 by winorth           #+#    #+#             */
/*   Updated: 2019/10/02 12:10:19 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

int	ft_getopt(int argc, char *const argv[], const char *optstr);

extern char	*g_optarg;
extern int	g_optind;
extern int	g_opterr;
extern int	g_optopt;
#endif
