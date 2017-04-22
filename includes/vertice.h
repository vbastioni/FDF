#ifndef VERTICE_H
# define VERTICE_H

typedef struct	    s_vert
{
    int		    x;
    int		    y;
    int		    z;
    int		    color;
}		    t_vert;

t_vert	*create_vert(int x, int y, char *data);

#endif
