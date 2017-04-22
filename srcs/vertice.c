#include <stdlib.h>

#include "libft.h"

#include "utils.h"
#include "vertice.h"

t_vert	*create_vert(int x, int y, char *data)
{
    t_vert  *v;
    char    **splitted;

    if (!(v = (t_vert *)malloc(sizeof(t_vert))))
	return (ptr_err("Could not create vertice.")); 
    if (!(splitted = ft_strsplit(data, ',')))
	return (ptr_err("Could not split data"));
    if (!splitted[1])
	ft_putendl("No data for color");
    v->x = x;
    v->y = y;
    v->z = ft_atoi(splitted[0]);
    v->color = splitted[1] ? ft_atoinbase(splitted[1]) : -1;
    return (v);
}
