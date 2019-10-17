/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmgr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 12:10:07 by winorth           #+#    #+#             */
/*   Updated: 2019/10/10 15:11:28 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMMGR_H
# define FT_MEMMGR_H
# include "../libft.h"

# define NOFREE             (~(SIZE_MAX >> 1))
# define CANFREE(mlink)     (!(mlink->size & NOFREE))
# define REALSIZE(x)        (x & (SIZE_MAX >> 1))
# define MLSIZE(mlink)      REALSIZE(mlink->size)

typedef struct		s_mlink
{
	struct s_mchain	*mchain;
	void			*ptr;
	size_t			size;
	struct s_mlink	*next;
}					t_mlink;

typedef struct		s_mchain
{
	char			label[26];
	int				link_count;
	struct s_mlink	*end;
	struct s_mlink	*start;
	struct s_mchain	*next;
}					t_mchain;

int					ft_mcdel(t_mchain *mchain);
int					ft_mcdelall(void);
int					ft_mcexists(const char *label);
t_mchain			*ft_mcget(const char *label);
t_mchain			**ft_mcgetall(void);

t_mlink				*ft_mladd(t_mchain *mchain, void *ptr, size_t size);
void				*ft_mlalloc(t_mchain *mchain, size_t size);
t_mlink				*ft_mlrev(t_mchain *mchain);
t_mlink				*ft_mlpop(t_mchain *mchain);

#endif
