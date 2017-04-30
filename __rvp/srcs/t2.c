#include "t2.h"

#include <stdlib.h>

t_t2    *t2_create(void *item1, void *item2)
{
    t_t2    *ret;

    if (!(ret = (t_t2 *)malloc(sizeof(t_t2))))
        return (NULL);
    ret->item1 = item1;
    ret->item2 = item2;
    return (ret);
}
