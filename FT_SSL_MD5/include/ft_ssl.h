/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:59:25 by winorth           #+#    #+#             */
/*   Updated: 2019/10/10 18:02:03 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include "../libft/libft.h"
# include <errno.h>
# define ROTL(x, c)		(((x) << (c)) | ((x) >> (32 - (c))))
# define ROTR(x, c)		(((x) >> (c)) | ((x) << (32 - (c))))

typedef struct			s_md5ctx
{
	uint32_t			state[4];
	uint32_t			count[2];
	unsigned char		buff[256];
}						t_md5ctx;

typedef struct			s_sha256ctx
{
	uint32_t			state[8];
	uint32_t			count[2];
	unsigned char		buff[256];
}						t_sha256ctx;

typedef union			u_ctx
{
	t_md5ctx			md5;
	t_sha256ctx			sha256;
}						t_ctx;

typedef struct			s_ssl
{
	t_ctx				ctx;
	char const			*arg;
	int					hash_type;
	int					quiet;
	int					reverse;
}						t_ssl;

typedef struct			s_digest
{
	int					type;
	void				(*init)(t_ssl *);
	void				(*update)(t_ssl *, unsigned char const *, size_t);
	void				(*final)(t_ssl *, unsigned char *);
	char const			*name;
	int					bsize;
}						t_digest;

enum					e_hash
{
	UNDEFINED,
	MD5,
	SHA256
};

/*
** MD5 Functions
*/

void					md5_init(t_ssl *ssl);
void					md5_update(t_ssl *ssl, unsigned char const *msg,
		size_t len);
void					md5_final(t_ssl *ssl, unsigned char *digest);

/*
** SHA256 Functions
*/

void					sha256_init(t_ssl *ssl);
void					sha256_update(t_ssl *ssl, unsigned char const *msg,
		size_t len);
void					sha256_final(t_ssl *ssl, unsigned char *digest);

/*
** Hash Functions
*/

void					hash_string(t_ssl *ssl, char const *arg);
void					hash_file(t_ssl *ssl, char const *filename);

/*
** Utility Functions
*/

void					usage(void);
void					rev_endian32(uint32_t *tab, int len);
void					rev_endian64(uint64_t *tab, int len);

extern char const		*g_pname;
extern t_digest const	g_digests[];
extern int	const		g_digests_size;
#endif
