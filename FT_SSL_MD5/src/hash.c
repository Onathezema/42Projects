/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:49:42 by winorth           #+#    #+#             */
/*   Updated: 2019/10/09 18:30:17 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl.h"
#include "../libft/libft.h"

t_digest const g_digests[] = {
	{ MD5, md5_init, md5_update, md5_final, "MD5", 16 },
	{ SHA256, sha256_init, sha256_update, sha256_final, "SHA256", 32 }
};

int const		g_digests_size = sizeof(g_digests) / sizeof(t_digest);

static void		print_hash(t_ssl *ssl, unsigned char const *digest, int quote)
{
	t_digest const	*algo;
	int				i;

	i = 0;
	algo = &g_digests[ssl->hash_type - 1];
	while (i < algo->bsize && ssl->reverse)
	{	
		ft_printf("%02x", digest[i++]);
	}
	if (ssl->arg && !ssl->quiet)
	{
		if (ssl->reverse && !quote)
			ft_printf(" %s", ssl->arg);
		else if (ssl->reverse)
			ft_printf(" \"%s\"", ssl->arg);
		else if (quote)
			ft_printf("%s (\"%s\") = ", algo->name, ssl->arg);
		else
			ft_printf("%s (%s) = ", algo->name, ssl->arg);
	}
	while (i < algo->bsize && !(ssl->reverse))
		ft_printf("%02x", digest[i++]);
	ft_printf("\n");
}

void			hash_string(t_ssl *ssl, char const *arg)
{
	t_digest const	*algo;
	unsigned char	digest[32];

	algo = &g_digests[ssl->hash_type - 1];
	ssl->arg = arg;
	algo->init(ssl);
	algo->update(ssl, (unsigned char const *)arg, ft_strlen(arg));
	algo->final(ssl, digest);
	print_hash(ssl, digest, TRUE);
}

void			hash_file(t_ssl *ssl, char const *filename)
{
	t_digest const	*algo;
	unsigned char	buff[4096];
	unsigned char	digest[32];
	int				bytes;
	int				fd;

	if (!(ssl->arg = filename))
		fd = 0;
	else if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_printf("%s: %s: %s\n", g_pname, filename, strerror(errno));
		return ;
	}
	algo = &g_digests[ssl->hash_type - 1];
	algo->init(ssl);
	while ((bytes = read(fd, buff, 4096)) > 0)
	{
		algo->update(ssl, buff, bytes);
		if (fd == STDIN_FILENO)
			write(STDOUT_FILENO, buff, bytes);
	}
	if (fd)
		close(fd);
	algo->final(ssl, digest);
	print_hash(ssl, digest, FALSE);
}
