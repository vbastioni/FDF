#include <mlx.h>

#include "libft.h"

#include "board.h"
#include "parsing.h"
#include "data.h"
#include "displays.h"
#include "color.h"
#include "vertice.h"

#include "dims.h"
#include "img_data.h"

void	draw(t_pixel *px, t_img_data *data, t_dims padding, int inter)
{
    int		n;
    int		color;

    n = padding.y * data->sl +
	px->vert->y * (data->sl * inter) +
	padding.x * data->bpx +
	px->vert->x * (data->bpx * inter);
    debug_vert(px->vert);
    if (px->vert->color >= 0)
	color = px->vert->color;
    else if (px->vert->z == 1)
	color = MAX_COLOR;
    else if (px->vert->z == -1)
	color = MIN_COLOR;
    else
	color = 0xFF0000;
    *(data->beg + n + 0) = color & 0xFF;
    *(data->beg + n + 1) = (color & 0xFF00) >> 8;
    *(data->beg + n + 2) = (color & 0xFF0000) >> 16;
}

int	display(t_board	*board, t_data *data)
{
    void	*img;
    t_img_data	*idata;
    t_pixel	*px;
    t_dims	padding;
    t_dims	inter;

    px = board->pixel;
    img = mlx_new_image(data->mlx, 400, 400);
    idata = ImgData_create();
    idata->beg = 
	mlx_get_data_addr(img, &idata->bpx, &idata->sl, &idata->endian);
    idata->bpx /= 8;
    inter.x = (400 - board->width) / (board->width - 1);
    inter.y = (400 - board->height) / (board->height - 1);
    padding.x = (400 - inter.x * (board->width - 1)) / 2;
    padding.y = (400 - inter.y * (board->height - 1)) / 2;
    while (px)
    {
	draw(px, idata, padding, inter.x < inter.y ? inter.x : inter.y);
	px = px->next;
    }
    mlx_put_image_to_window (data->mlx, data->win, img, 0, 0);
    return (1);
}
