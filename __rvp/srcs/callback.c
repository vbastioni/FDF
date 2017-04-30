#include "callback.h"

#include <mlx.h>
#include <stdlib.h>

#include "wdata.h"
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

static int  change_imgs(int keycode, t_wdata *wdata, void **imgs)
{
    (void)wdata;
    (void)imgs;
    ft_putstr("Pressed ");
    if (keycode == 18) {
        ft_putnbr(keycode);
        ft_putstr(": 1.\n");
    } else if (keycode == 19) {
        ft_putnbr(keycode);
        ft_putstr(": 2.\n");
    }
    return (0);
}

int     handle_key(int keycode, void *param)
{
    void    **imgs;
    t_wdata *wdata;
    t_t2    *t2;

    t2 = (t_t2 *)param;
    wdata = (t_wdata *)(t2)->item1;
    imgs = (void **)(t2)->item2;
    if (keycode == KEY_EXIT)
        exit_prg(wdata);
    else if (keycode == 18 || keycode == 19)
        change_imgs(keycode, wdata, imgs);
    else
        print_keycode(keycode);
    return (0);
}