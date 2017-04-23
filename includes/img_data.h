#ifndef IMG_DATA_H
# define IMG_DATA_H

typedef struct	s_img_data
{
    int		bpx;
    int		sl;
    int		endian;
    char	*beg;
}		t_img_data;

t_img_data	*ImgData_create();

#endif
