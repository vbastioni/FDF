#include "callback.h"

#include <mlx.h>
#include <stdlib.h>

#include "wdata.h"
#include "imgdata.h"
#include "t2.h"
#include "libft.h" //

static int  exit_prg(t_wdata *wdata)
{
    mlx_destroy_window(wdata->mlx, wdata->win);
    free(wdata);
    exit(0);
    return (0);
}

static int  print_keycode(int keycode)
{
    ft_putstr("Pressed keycode: '");
    ft_putnbr(keycode);
    ft_putstr("'\n");
    return (0);
}

static int  change_imgs(int keycode, t_wdata *wdata, t_imgdata *iptr)
{
    (void)wdata;
    (void)iptr;
    ft_putstr("Pressed ");
    if (keycode == KEY_PARA) {
        ft_putnbr(keycode);
        ft_putstr(": 1.\n");
    } else if (keycode == KEY_ISO) {
        ft_putnbr(keycode);
        ft_putstr(": 2.\n");
    }
    return (0);
}

int     handle_key(int keycode, void *param)
{
    t_imgdata   *iptr;
    t_wdata     *wdata;
    t_t2        *t2;

    t2 = (t_t2 *)param;
    wdata = (t_wdata *)(t2)->item1;
    iptr = (t_imgdata *)(t2)->item2;
    if (keycode == KEY_EXIT)
        exit_prg(wdata);
    else if (keycode == 18 || keycode == 19)
        change_imgs(keycode, wdata, iptr);
    else
        print_keycode(keycode);
    return (0);
}