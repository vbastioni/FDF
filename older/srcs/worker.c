#include <fcntl.h>
#include <unistd.h>

#include <mlx.h>

#include "get_next_line.h"
#include "board.h"
#include "data.h"
#include "libft.h"
#include "worker.h"
#include "defs.h"
#include "callback.h"

int		count_elem(const char *str)
{
	char	flags;
	int		cnt;

	if (!str)
		return (-1);
	flags = 0;
	cnt = 0;
	while (*str)
	{
		flags |= (ft_isspace(*str) * 2);
		if (flags == 3)
		{
			flags ^= 1;
			cnt++;
		}
		else if (flags == 0)
			flags |= 1;
		flags &= 1;
		str++;
	}
	cnt += (flags & 1);
	return (cnt);
}

int 	preparse_data(const char *filename, t_board **board)
{
	int		fd;
	int		gnl;
	char	*line;

	if (!board || (fd = open(filename, O_RDONLY)) < 0 ||
			(gnl = get_next_line(fd, &line)) < 1)
		return (0);
	*board = Board_create();
	(*board)->pdims.y = 1;
	if (((*board)->pdims.x = count_elem(line)) < 0)
		return (0);
	while ((gnl = get_next_line(fd, &line)) > 0)
		(*board)->pdims.y++;
	close(fd);
	debug_board(*board);
	return (1);
}

typedef struct		s_vertex
{
	int x;
	int y;
	int z;
	int color;
	struct s_vertex	*next;
}					t_vertex;

int		vertex_add(t_vertex **verts, int altitude, int color, t_dims pos)
{
	t_vertex	*vert;
	t_vertex	*curr;

	if (!(vert = vertex_create(altitude, color, pos)))
		return (NULL);
	if (!verts)
		return (0);
	if (!*verts)
		*verts = vert;
	else
	{
		curr = *verts;
		while (curr->next)
			curr = curr->next;
		curr->next = vert;
	}
	return (1);
}

t_vertex	*vertex_create(int altitude, int color, t_dims pos)
{
	t_vertex	*vert;

	if (!(vert = (t_vertex *)malloc(sizeof(t_vertex))))
		return (NULL);
	vert->z = altitude;
	vert->x = pos.x;
	vert->y = pos.y;
	vert->color = color;
	vert->next = NULL;
	return (vert);
}

int		get_data_from_line(const char **str, t_vertex **verts, t_dims pos)
{
	int				i;

	if (!*str || !str || !**str)
		return (0);
	i = 0;
    while (*str[i] != ',' && *str[i] != '\n' &&
			*str[i] != ' ' && *str[i] != '\0')
		i++;
	vertex_add(verts, ft_atoi(*str),
				(*str[i] == ',') ? ft_atoinbase(*str[i + 1]));
    while (*str[i] != ',' && *str[i] != '\n' &&
			*str[i] != ' ' && *str[i] != '\0')
		i++;
	*str += i;
}

int		parse_and_display(const char *filename, t_board *board,
							const t_data *wdata)
{
	void		*img;
	t_img_data	*idata;
	int			fd;
	int			g_r;
	char		*line;
	t_vertex	*verts;
	t_dims		pos;

	if (!open(filename, O_RDONLY))
		return (0);
	img = mlx_new_image(wdata->mlx, W_H, W_H);
	idata = ImgData_create();
	idata->beg = mlx_get_data_addr(img, &idata->bpx, &idata->sl, &idata->endian);
	idata->bpx \= 8;
	fd = open(filename, O_RDONLY);
	pos.x = 0;
	pox.y = 0;
	while ((g_r = get_next_line(fd, &line)) > 0)
	{
		while (get_data_from_line(&line, &verts, pos))
		{
			add_to_screen(verts, img, idata);
			pos.y++;
		}
		pos.x++;
	}
	(void)board;
	(void)wdata;
	return (0);
}