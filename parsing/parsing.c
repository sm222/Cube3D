
#include "parsing.h"
#include <errno.h>
#include <string.h>

static int	look_name(char *name)
{
	char	*tmp;

	if (!name)
		return (-1);
	tmp = ft_strrchr(name, '.');
	if (!tmp || ft_strncmp(tmp, ".cub", 5) != 0)
	{
		ft_printf(2, "%oCub3D : "RED"%s"WHT" don't finish in .cub\n", \
		NULL, name);
		return (-1);
	}
	return (1);
}

static int	open_file(t_parsing *data, char *file)
{
	if (look_name(file) < 0)
		return (-1);
	data->fd = open(file, O_RDONLY | O_DIRECTORY);
	if (data->fd > 0)
	{
		close(data->fd);
		ft_printf(2, "%oCub3D : "RED"%s"WHT" is a directory\n", NULL, file);
		return (-1);
	}
	data->fd = open (file, O_RDONLY);
	if (data->fd < 0)
	{
		ft_printf(2, "%oCub3D : "RED"%s"WHT" %s\n", NULL, \
		file, strerror(errno));
		return (data->fd);
	}
	return (data->fd);
}

t_map	parsing(char *arg)
{
	t_parsing	data;

	ft_bzero(&data, sizeof(t_parsing));
	if (!arg)
		return (NULL);
	if (open_file(&data, arg) == -1)
		return (NULL);
	return (data.map);
}
