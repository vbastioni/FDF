#include "tX.h"

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

t_t3    *t3_create(void *i1, void *i2, void *i3)
{
    t_t3    *ret;

    if (!(ret = (t_t3 *)malloc(sizeof(t_t3))))
        return (NULL);
    ret->item1 = i1;
    ret->item2 = i2;
    ret->item3 = i3;
    return (ret);
}