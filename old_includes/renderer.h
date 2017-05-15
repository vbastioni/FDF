#ifndef RENDERER_H
# define RENDERER_H

#include "board.h"
#include "imgdata.h"
#include "wdata.h"

typedef enum	e_mode
{
	PAR = 0,
	ISO = 1
}				t_mode;

typedef enum	e_dir
{
	RIG = 0,
	BOT = 1,
	DIA = 2
}				t_dir;                  

void			render(const t_board *board, t_imgdata *iptr, t_mode mode,
						t_wdata *wdata);
void			render_par(const t_board *board, const t_imgdata *iptr, 
                            t_dims *delta);
void			render_iso(const t_board *board, const t_imgdata *iptr, 
                            t_dims *delta);

void			(*rdrs[2])(const t_board *board, const t_imgdata *ptr, 
                            t_dims *delta);

#endif