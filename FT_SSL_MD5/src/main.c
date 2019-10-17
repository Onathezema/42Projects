/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:49:46 by winorth           #+#    #+#             */
/*   Updated: 2019/10/09 20:32:37 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_ssl.h"
#include "../libft/include/ft_getopt.h"

char const		*g_pname;

static int		processflags(int argc, char *const argv[], t_ssl *ssl)
{
	char	flag;
	int		hashed;

	hashed = FALSE;
	while ((flag = ft_getopt(argc, argv, "pqrs:")) != -1)
	{
		if (flag == 'q')
			ssl->quiet = TRUE;
		else if (flag == 'r')
			ssl->reverse = TRUE;
		else if (flag == 'p')
		{
			hash_file(ssl, NULL);
			hashed = TRUE;
		}
		else if (flag == 's')
		{
			hash_string(ssl, g_optarg);
			hashed = TRUE;
		}
		else
			usage();
	}
	return (hashed);
}

static int		set_mode(int argc, char *argv[], t_ssl *ssl)
{
	t_digest const	*algo;
	int				i;

	if (argc < 2)
		return (FALSE);
	i = 0;
	ft_strupcase(argv[1]);
	while (i < g_digests_size)
	{
		algo = &g_digests[i++];
		if (!strcmp(algo->name, argv[1]))
		{
			ssl->hash_type = algo->type;
			break ;
		}
	}
	if (!ssl->hash_type)
		return (FALSE);
	ft_memcpy(&argv[1], &argv[2], sizeof(char *) * (argc));
	return (TRUE);
}

int				main(int argc, char *argv[])
{
	static t_ssl	ssl;
	int				hashed;

	g_pname = argv[0];
	if (!set_mode(argc--, argv, &ssl))
		usage();
	hashed = processflags(argc, argv, &ssl);
	if (!hashed && g_optind == argc)
		hash_file(&ssl, NULL);
	while (g_optind < argc)
		hash_file(&ssl, argv[g_optind++]);
	return (0);
}
