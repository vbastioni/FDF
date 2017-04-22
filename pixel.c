#include <stdlib.h>

#include "pixel.h"

int	lstadd(t_pixel **lst, t_vert *vert)
{
    t_pixel  *c;
    if (!lst)
	return (0);
    if (!*lst)
    {
	if (!(c = (t_pixel *)malloc(sizeof(t_pixel))))
	    return (0);
	c->vert = vert;
	c->next = 0;
	c->prev = 0;
	*lst = c;
    }
    else
    {
	c = *lst;
	while (c->next)
	    c = c->next;
	if (!(c->next = (t_pixel *)malloc(sizeof(t_pixel))))
	    return (0);
	c->next->vert = vert;
	c->next->prev = c;
	c->next->next = 0;
    }
    return (1);
}
