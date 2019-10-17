/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:10:34 by winorth           #+#    #+#             */
/*   Updated: 2019/10/04 18:02:37 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include "../../include/ft_getopt.h"

char		*g_optarg;
int			g_optind = 1;
int			g_opterr = 1;
int			g_optopt;

static int		opt_error(char *pname, const char *err, const char *optstr)
{
	char	*msg;
	char	*temp;
	int		len;

	if (g_opterr && *optstr != ':')
	{
		len = ft_strlen(pname) + ft_strlen(err) + 9;
		if (!(msg = ft_memalloc(len)))
			return ('?');
		temp = msg;
		temp = ft_stpcpy(temp, pname);
		temp = ft_stpcpy(temp, ": ");
		temp = ft_stpcpy(temp, err);
		temp = ft_stpcpy(temp, " -- ");
		*temp++ = g_optopt;
		*temp = '\n';
		write(STDERR_FILENO, msg, len);
		free(msg);
	}
	return ((*optstr == ':') ? ':' : '?');
}

static int		set_arg(char *const argv[], char **pos, const char *op)
{
	int	optional;

	g_optarg = NULL;
	if (*(op + 1) != ':')
		return (TRUE);
	g_optarg = (**pos) ? *pos : argv[g_optind];
	optional = (*op && *(op + 2) == ':');
	if (optional && g_optarg && *g_optarg == '-')
		g_optarg = NULL;
	else
		++g_optind;
	*pos = NULL;
	return (g_optarg != NULL || optional);
}

static int		pro_arg(char *const argv[], const char *optstr)
{
	static char	*pos;
	const char	*op;

	if (!pos || !*pos)
		pos = argv[g_optind] + 1;
	g_optopt = *pos++;
	if (!*pos)
		++g_optind;
	if (!(op = ft_strchr(optstr, g_optopt)))
		return (opt_error(argv[0], "illegal option", optstr));
	if (!set_arg(argv, &pos, op))
		return (opt_error(argv[0], "option requires an argument", optstr));
	return (g_optopt);
}

int				ft_getopt(int argc, char *const argv[], const char *optstr)
{
	if (g_optind == 1)
	{
		g_optarg = NULL;
		g_optopt = '\0';
	}
	if (g_optind < argc)
	{
		if (*argv[g_optind] != '-' || !*(argv[g_optind] + 1))
		{
			if (*optstr != '-')
				return (-1);
			g_optarg = argv[g_optind++];
			return ((g_optopt = '\1'));
		}
		if (!ft_strcmp(argv[g_optind], "--"))
		{
			g_optopt = '-';
			++g_optind;
			return (-1);
		}
		return (pro_arg(argv, optstr));
	}
	return (-1);
}
