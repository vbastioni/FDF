#ifndef T2_H
# define T2_H

typedef struct  s_t2
{
    void        *item1;
    void        *item2;
}               t_t2;

typedef struct  s_t3
{
    void        *item1;
    void        *item2;
    void        *item3;
}               t_t3;

t_t2            *t2_create(void *item1, void *item2);
t_t3            *t3_create(void *i1, void *i2, void *i3);

#endif