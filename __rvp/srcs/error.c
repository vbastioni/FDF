#include "fdf.h"

int             err(const char *str)
{
#ifdef DEBUG
    ft_putstr("\e[31m");
    ft_putstr(str);
    ft_putstr("\e[0m");
#else
    (void)str;
#endif
    return (1);
}