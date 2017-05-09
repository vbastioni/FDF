#ifndef FDF_H
# define FDF_H

# include <stdlib.h>

# define WIN_X 800
# define WIN_Y 800
# define WIN_NAME "FdF"

typedef unsigned char	t_uchar;

typedef enum			e_mode
{
	PAR = 0,
	ISO = 1
}						t_mode;

typedef enum			e_dir
{
	RIG = 0,
	BOT = 1,
	DIA = 2
}						t_dir;

typedef struct			s_dims
{
	int					x;
	int					y;
}						t_dims;

t_dims					dims_zero();
t_dims					dims_create(int x, int y);

typedef struct			s_t2
{
	void				*item1;
	void				*item2;
}						t_t2;

typedef struct			s_t3
{
	void				*item1;
	void				*item2;
	void				*item3;
}						t_t3;

t_t2					*t2_create(void *item1, void *item2);
t_t3					*t3_create(void *i1, void *i2, void *i3);

typedef struct			s_vector
{
	int					x;
	int					y;
	int					z;
}						t_vector;

typedef struct			s_fvector
{
	float				a;
	float				b;
}						t_fvector;

typedef union			u_color
{
	int					color;
	t_uchar				c[4];	
}						t_color;

typedef struct			s_vertex
{
	t_vector			pos;
	t_color				color;
}						t_vertex;

typedef struct			s_env
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
	void				(*rdr)(const struct s_env *env);	
}						t_env;

void					env_setup(t_env *env);

int						preparse_data(const char *filename, t_env *env);
int						parse_data(const char *filename, t_env *env);

/*
**	CALLBACKS
*/

int						cb_expose(void *param);

int						cb_key(int keycode, void *param);

#endif