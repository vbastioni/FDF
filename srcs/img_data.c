#include <stdlib.h>

#include "img_data.h"

t_img_data	*ImgData_create()
{
    t_img_data	*ret;

    if (!(ret = (t_img_data *)malloc(sizeof(t_img_data))))
	return (NULL);
    ret->bpx = 0;
    ret->sl = 0;
    ret->endian = 0;
    ret->beg = NULL;
    return (ret);
}
