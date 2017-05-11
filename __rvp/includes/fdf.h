#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include "libft.h"
#include <stdio.h> //

# define WIN_X 800
# define WIN_Y 800
# define WIN_NAME ("FdF")

# define COL_LOW_1 (0xFFFFFF)
# define COL_LOW_2 (0xFF00FF)
# define COL_LOW_3 (0x15439B)

# define COL_HIGH_1 (0x0)
# define COL_HIGH_2 (0xFFFF00)
# define COL_HIGH_3 (0x9B4815)

# define KC_EXIT 53
# define KC_CHANGE_COLOR 49
# define KC_TURN_LEFT 123
# define KC_TURN_RIGHT 124

#define EVT_CLOSE_WIN 11

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

void					draw_par(const t_env *env);

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
**	APP ENVIRONMENT VARIABLES.
*/

struct					s_env
{
	void				*mlx;
	void				*win;
	t_vertex			**vertex;
	t_dims				pdims;
	t_dims				alts;
	t_dims				bounds[4];
	t_mode				render_mode;
	t_dims				par_delta;
	t_dims				par_inter;
	t_dims				iso_delta;
	t_dims				iso_inter;
	float				iso_rot;
	t_dims				color_sets[3];
	int					color_id;
	void				(*rdr)(const t_env *env);	
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

int						cb_key(int keycode, void *param);

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

#endif