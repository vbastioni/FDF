#ifndef WDATA_H
# define WDATA_H

typedef struct  s_wdata
{
    void        *mlx;
    void        *win;
}               t_wdata;

t_wdata         *create_window();

#endif