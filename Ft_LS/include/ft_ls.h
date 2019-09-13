/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:44:36 by winorth           #+#    #+#             */
/*   Updated: 2019/09/09 15:25:57 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"

# define ST_MTIMESPEC st_mtim
# define ST_ATIMESPEC st_atim
# define S_IFWHT 0160000

# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <string.h>
# include <errno.h>
# include <sys/ioctl.h>

typedef	struct s_flagtypes	t_flagtypes;
typedef struct s_dips		t_dips;
typedef struct s_rec		t_rec;
typedef	struct s_filetypes	t_filetypes;
typedef	enum e_lsflag		t_lsflag;

struct	s_dips
{
	char		*name;
	struct stat	*stats;
	int			flags;
	char		*dirp;
	char		*user;
	char		*group;
	long		size;
	int			size_pad;
	int			link_pad;
	int			userlen;
	int			grouplen;
	t_dips		*next;
};

struct	s_flagtypes
{
	char	type;
	int		flag;
};

struct	s_rec
{
	t_dips		*direc;
	t_rec		*next;
};

struct	s_filetypes
{
	int		type;
	char	c;
	char	*color;
	char	c2;
};

enum	e_lsflag
{
	LL = 2, RR = 4, aa = 8, rr = 16, tt = 32, gg = 64, ff = 128, GG = 256,
	oo = 512, AA = 1024, dd = 2048, uu = 4096, FF = 8192, HH = 16384
};

int		main(int argc, char **argv);
void	deldirp(char **dirp);
int		fit(int ex, t_dips *d, int col);
int		type(struct stat stats, unsigned int type);
int		end(t_dips *dir);
void	peveryi(t_dips *d, int i, int len);
void	pcols(t_dips *d, int cols, int size, int len);
void	countcol(t_dips *d, int len, int count);
int		checklen(int len, int cmp);
void	pcol(t_dips *d);
int		printerror(char *dirp, int errnum);
int		error_flags(char err);
int		inputtest(char *inp, int flags);
char	*inputfix(char *in);
void	chec_recur(t_rec **recur);
t_dips	*readdirec(char *dirp, DIR *str, int flags);
int		ft_ls(char *dirp, int flags);
void	userlen_fix(t_dips **dir, int size);
void	grouplen_fix(t_dips **dir, int size);
void	linkpad_fix(t_dips **dir, int size);
void	sizepad_fix(t_dips **dir, int size);
void	print_one(char *file, int flags);
void	ptime(struct stat *info);
void	pperm(struct stat *info, int b);
void	pinfo(t_dips *d);
void	plink(t_dips *d);
void	plist(t_dips *d);
t_rec	*recnew(t_dips *dirp);
void	recadd(t_dips *dirp, t_rec **rec);
void	recdel(t_rec *rec);
char	*hgid(gid_t st_gid);
char	*huid(uid_t st_uid);
int		usorted(t_dips *dirp1, t_dips *dirp2);
void	usort(t_dips **lst);
void	sorting(t_dips **dirp, int flags);
void	blocs(t_dips *dir);
int		pchar(t_dips *d, int i, int width);
void	pname(t_dips *d, int i, int width);
void	ptype(t_dips *d, int width);
void	print_mm(t_dips *d);
int		sorted(char *str1, char *str2);
int		tsorted(t_dips *dirp1, t_dips *dirp2);
void	fsort(t_dips **lst);
void	tsort(t_dips **lst);
void	dirsort(t_dips **lst);
char	**getdirp(int s, char **in, int flags);
int		oneflag(int flag);
int		getflag(char *str);
int		getflags(char **str, int s);
int		adddir(t_dips **dir, struct dirent *ent);
void	dirpfill(t_dips **dir);
t_dips	*newdir(char *name, char *path, int flags);
void	dirdel(t_dips *dir);
void	dirpswap(t_dips **curr);

#endif
