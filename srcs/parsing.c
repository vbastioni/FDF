#include <stdlib.h>

#include "utils.h"
#include "parsing.h"

int	validate(char *line, int y, t_pixel **lst)
{
    char    **splitted;
    t_vert  *v;
    int	    i;

    if (!lst)
	return (-1);
    i = 0;
    splitted = ft_strsplit(line, ' ');
    while (*(splitted + i))
    {
	if (!(v = create_vert(i, y, *(splitted + i))))
	    return (-err("Mem error in create vertice.")); // here too.
	if (!(lstadd(lst, v)))
	    return (-err("Mem error in lstadd")); // do cleaner for pixel
	free(*(splitted + i));
	debug_vert(v);
	i++;
    }
    return (0);
}

void	debug_vert(const t_vert *vert)
{
    ft_putstr("x: ");
    ft_putnbr(vert->x);
    ft_putstr(", y: ");
    ft_putnbr(vert->y);
    ft_putstr(", z: ");
    ft_putnbr(vert->z);
    ft_putstr(", color: ");
    ft_putnbr(vert->color);
    ft_putendl(".");
}
