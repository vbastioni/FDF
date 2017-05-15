#include "callback.h"

#include <mlx.h>
#include <stdlib.h>

#include "wdata.h"
#include "renderer.h"
#include "imgdata.h"
#include "tX.h"

static int  exit_prg(t_wdata *wdata)
{
    mlx_destroy_window(wdata->mlx, wdata->win);
    free(wdata);
    exit(0);
    return (0);
}

static int  change_imgs(int keycode, t_board *board, t_wdata *wdata,
                        t_imgdata *iptr)
{
    if (keycode == KEY_PARA)
        render(board, iptr, PAR, wdata);
    else if (keycode == KEY_ISO)
        render(board, iptr, ISO, wdata);
    return (0);
}

int     handle_key(int keycode, void *param)
{
    t_imgdata   *iptr;
    t_wdata     *wdata;
    t_t3        *t3;
    t_board     *board;

    t3 = (t_t3 *)param;
    board = (t_board *)(t3)->item1;
    wdata = (t_wdata *)(t3)->item2;
    iptr = (t_imgdata *)(t3)->item3;
    if (keycode == KEY_EXIT)
        exit_prg(wdata);
    else if (keycode == 18 || keycode == 19)
        change_imgs(keycode, board, wdata, iptr);
    return (0);
}