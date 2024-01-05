
#include "parsing.h"

static int	look_name(char *name)
{
	char	*tmp;

	if (!name)
		return (-1);
	tmp = ft_strrchr(name, '.');
	if (!tmp || ft_strncmp(tmp, ".cub", 5) != 0)
	{
		ft_printf(2, "%oError\nCub3D: "RED"%s"WHT" don't finish in .cub\n", \
		NULL, name);
		if (tmp)
			ft_print_err_len((tmp - name) + 7);
		else
			ft_print_err_len(ft_strlen(name) + 7);
		return (-1);
	}
	return (1);
}

int	open_file(t_parsing *data, char *file)
{
	if (look_name(file) < 0)
		return (-1);
	data->fd = open(file, O_RDONLY | O_DIRECTORY);
	if (data->fd > 0)
	{
		close(data->fd);
		ft_printf(2, "%oError\nCub3D: "RED"%s"WHT" is a directory\n", \
		NULL, file);
		return (-1);
	}
	data->fd = open (file, O_RDONLY);
	if (data->fd < 0)
	{
		ft_printf(2, "%oCub3D: "RED"%s"WHT" %s\n", NULL, \
		file, strerror(errno));
		return (data->fd);
	}
	return (data->fd);
}

static void	fix_empty(char **line)
{
	char	*new;

	new = NULL;
	if (*line)
	{
		if (*line[0] && *line[0] == '\n')
		{
			new = ft_strjoin(" ", *line);
			if (new)
			{
				*line = ft_free(*line);
				*line = new;
			}
		}
	}
}

/// @brief 
/// @param data 
/// @return 
t_err	read_map(t_parsing *data)
{
	char	*tmp;
	char	*join;
	size_t	line;

	line = 0;
	tmp = "read";
	join = NULL;
	while (tmp)
	{
		tmp = get_next_line(data->fd);
		if (tmp == NULL && line == 0)
			return (e_empty_map);
		line++;
		fix_empty(&tmp);
		join = ft_strfjoin(join, tmp);
		ft_free(tmp);
		if (!join)
			return (e_malloc_f);
	}
	data->pre_map = ft_split(join, '\n');
	ft_free(join);
	if (!data->pre_map)
		return (e_malloc_f);
	return (e_success);
}
