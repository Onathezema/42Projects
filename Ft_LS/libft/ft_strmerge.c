#include "libft.h"

char	*ft_strmerge(char *a, char *b)
{
	char	*res;

	res = ft_strjoin(a, b);
	ft_strdel(&a);
	ft_strdel(&b);
	return (res);
}
