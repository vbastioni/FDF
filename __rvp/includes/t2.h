#ifndef T2_H
# define T2_H

typedef struct  s_t2
{
    void        *item1;
    void        *item2;
}               t_t2;

t_t2            *t2_create(void *item1, void *item2);

#endif