/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 12:51:29 by vbastion          #+#    #+#             */
/*   Updated: 2017/05/17 11:16:29 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>

# include <stdlib.h>
# include <math.h>

# include <stdio.h>

# include "libft.h"

# define WIN_X 1200
# define WIN_Y 1200
# define WIN_NAME ("FdF")

/*
**	MATH AND ISO STUFFS
*/

# ifdef PI
#  undef PI
# endif
# define PI (3.14159265358979323846)
# define TO_RAD (0.01745329251994329577)
# define TO_DEG (57.2957795130823208768)

# define Z_COEFF (0.10)
# define ANG (30)
# define OPP_ANG (ANG + 120)
# define ANGLE_STEP (90)
# define MOVE_STEP (5)

# define DEF_ZOOM (50.)
# define DEF_ANG_X (45)
# define DEF_ANG_Y (30)

/*
**	COLORS
*/

# define COL_LOW_1 (0xFFFFFF)
# define COL_LOW_2 (0xFF00FF)
# define COL_LOW_3 (0x15439B)
# define COL_LOW_4 (0x9FC627)

# define COL_HIGH_1 (0x0)
# define COL_HIGH_2 (0xFFFF00)
# define COL_HIGH_3 (0x9B4815)
# define COL_HIGH_4 (0xC627A1)

/*
**	KEYCODES
*/

# define KC_PAR 18
# define KC_ISO 19
# define KC_EXIT 53
# define KC_CHANGE_COLOR 49
# define KC_LEFT 123
# define KC_RIGHT 124
# define KC_UP 126
# define KC_DOWN 125
# define KC_PG_UP 116
# define KC_PG_DOWN 121

# define KC_Q 12
# define KC_E 14
# define KC_R 15

# define KC_W 13
# define KC_S 1
# define KC_A 0
# define KC_D 2

# define KC_O 31
# define KC_P 35

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_PRESS_MASK 1L << 0
# define KEY_RELEASE_MASK 1L << 1

# define DESTROY_NOTIFY 17
# define NO_EVENT_MASK 0L

/*
**	APP EVENT
*/

# define EVT_CLOSE_WIN 11

/*
** # define DestroyNotify	17
*/

/*
**	typedefs
*/

typedef unsigned char	t_uchar;

typedef enum e_mode		t_mode;
typedef enum e_dir		t_dir;

typedef struct s_dims	t_dims;
typedef struct s_t2		t_t2;
typedef struct s_t3		t_t3;
typedef struct s_vector	t_vector;
typedef struct s_vertex	t_vertex;
typedef struct s_img	t_img;
typedef struct s_env	t_env;

typedef union u_color	t_color;

/*
**	SPECIALIZED DATA CONTAINERS
*/

struct					s_vector
{
	int					x;
	int					y;
	int					z;
};

typedef struct			s_fvector
{
	float				a;
	float				b;
}						t_fvector;

/*
**	DRAW
*/

enum					e_mode
{
	PAR = 0,
	ISO = 1
};

enum					e_dir
{
	RIG = 0,
	BOT = 1,
	DIA = 2
};

int						draw_par(const t_env *env);
int						draw_iso(const t_env *env);
t_fvector				get_iso_pos(t_vector *pos, const t_env *env);
void					set_env_iso_delta(t_env *e);

/*
** DIMS
*/

struct					s_dims
{
	int					x;
	int					y;
};

t_dims					dims_zero();
t_dims					dims_create(int x, int y);

/*
**	GENERIC CONTAINERS
*/

struct					s_t2
{
	void				*item1;
	void				*item2;
};

struct					s_t3
{
	void				*item1;
	void				*item2;
	void				*item3;
};

t_t2					*t2_create(void *item1, void *item2);
t_t3					*t3_create(void *i1, void *i2, void *i3);

/*
**	COLOR
*/

union					u_color
{
	int					color;
	t_uchar				c[4];
};

int						color_lerp(int c_a, int c_b, double progress);
int						col_get(t_vertex v, const t_env *env);

struct					s_vertex
{
	t_vector			pos;
	t_color				color;
};

/*
**	Image container
*/

struct					s_img
{
	void				*img;
	char				*addr;
	int					bpx;
	int					sl;
	int					endian;
};

int						img_set(t_img *img, const t_env *env);

/*
**	APP VARIABLES
*/

struct					s_env
{
	void				*mlx;
	void				*win;
	t_vertex			**vertex;
	t_dims				pdims;
	t_dims				alts;
	t_mode				render_mode;
	t_dims				par_d;
	t_dims				par_inter;
	float				zcoeff;
	t_dims				iso_d;
	t_dims				iso_offset;
	t_dims				iso_inter;
	t_fvector			iso_angles;
	float				iso_scale;
	t_dims				color_sets[5];
	int					color_set_id;
	int					color_set_cnt;
	int					color_id;
	int					(*rdr)(const t_env *env);
};

/*
**	DATA PARSING
*/

int						parse_data(char *filename, t_env *env);
int						preparse_data(char *filename, t_env *env);

/*
**	CALLBACKS
*/

int						cb_expose(void *param);
void					change_render(t_mode mode, t_env *env);
void					change_color(t_env *env);
int						reset_view(void *param);
int						cb_key(int keycode, void *param);
int						cb_cont_key(int kc, void *param);

int						err(const char *msg);
int						free_lines(t_env *env, int cnt);
int						on_win_close(t_env *e);
int						close_window(t_env *e);

#endif
