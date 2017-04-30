#include "libft.h"

int	convertible(const char *nbr, const char *base)
{
    int	i;

    while (*nbr)
    {
	i = 0;
	while (*(base + i))
	{
	    if (*nbr == *(base + i))
		break;
	    i++;
	}
	if (*nbr != *(base + i))
	    return (0);
	nbr++;
    }
    return (1);
}

int	index_in_base(const char c, const char *base)
{
    int	    i;

    i = 0;
    while (*(base + i))
    {
	if (*(base + i) == c)
	    return (i);
	i++;
    }
    return (0);
}

unsigned int	ft_atoibase(const char *nbr, const char *base)
{
    int		    i;
    unsigned int    ret;
    int	    blen;

    if (!nbr || !base || !ft_valid_base(base, &blen) ||
	!convertible(nbr, base))
	return (0);
    while (ft_isspace(*nbr))
	nbr++;
    ret = 0;
    i = 0;
    while (*(nbr + i))
	ret = ret * blen + index_in_base(*(nbr + i++), base);
    return (ret);
}
