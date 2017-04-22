#include <stdlib.h>

#include "libft.h"

#include "utils.h"

int	err(const char *str)
{
    ft_putstr("[ERR]: ");
    ft_putendl(str);
    return (0);
}

void	*ptr_err(const char *str)
{
    err(str);
    return (NULL);
}
