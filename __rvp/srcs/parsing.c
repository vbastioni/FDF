#include "fdf.h"

#include <fcntl.h>
#include <unistd.h>

#include "get_next_line.h"
#include "libft.h"

static inline int	count_elem(const char *str)
{
	char			flags;
	int				cnt;

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

static t_vertex		get_vertex(char **line, int x, int y)
{
	t_vertex		vec;

	vec.pos.x = x;
	vec.pos.y = y;
	vec.pos.z = ft_atoi(*line);
	while (ft_isspace(**line))
		(*line)++;
	if (*(*line) == '-' || *(*line) == '+')
		(*line)++;
	while (ft_isdigit(**line))
		(*line)++;
	if (ft_strncmp(*line, ",0x", 3) == 0)
	{
		(*line) += 3;
		vec.color.color = ft_atoihex(*line);
		while (ft_isalnum(**line))
			(*line)++;
	}
	else
		vec.color.color = -1;
	return (vec);
}

static int			convert_data(t_env *env, char *line, int y)
{
	int				x;
	int				cnt;

	cnt = count_elem(line);
	if (cnt != env->pdims.x)
		return (0 * (err("Wrong line #") | err(ft_itoa(y))
						| err(" element count. Awaited ")
						| err(ft_itoa(env->pdims.x)) | err(" and got ")
						| err(ft_itoa(cnt)) | err(" lines.\n")));
	if (!(env->vertex[y] = (t_vertex *)malloc(
			sizeof(t_vertex) * env->pdims.x)))
		return (0 * err("Could not allocate memory"));
	x = -1;
	while (++x < env->pdims.x)
	{
		env->vertex[y][x] = get_vertex(&line, x, y);
		if (env->vertex[y][x].pos.z > env->alts.y)
			env->alts.y = env->vertex[y][x].pos.z;
		else if (env->vertex[y][x].pos.z < env->alts.x)
			env->alts.x = env->vertex[y][x].pos.z;
	}
	return (1);
}

int					preparse_data(char *filename, t_env *env)
{
	int				fd;
	int				gnl;
	char			*line;

	if ((fd = open(filename, O_RDONLY)) < 0
		|| (gnl = get_next_line(fd, &line)) < 1)
		return (0 * err("Either could not open or read the file.\n"));
	if ((env->pdims.x = count_elem(line)) < 0)
		return (0 * err("Must have a valid file and data.\n"));
	env->pdims.y = 1;
	free(line);
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		free(line);
		env->pdims.y++;
	}
	if (!(env->vertex = (t_vertex **)malloc(sizeof(t_vertex *) * 
											env->pdims.y)))
		return (0 * err("Could not allocate memory.\n"));
	close(fd);
	return (1);
}

int					parse_data(char *filename, t_env *env)
{
	int				fd;
	char			*line;
	int				y;
	int				gnl;
	int				ret_cd;

	y = 0;
	env->alts = dims_zero();
    if (!(fd = open(filename, O_RDONLY)))
		return (0);
	while ((gnl = get_next_line(fd, &line)) > 0 &&
			((ret_cd = convert_data(env, line, y++)) > 0))
		free(line);
	if (ret_cd == 0)
	{
		// FREE already allocated memory
		return (0);
	}
	close(fd);
	return (1);
}