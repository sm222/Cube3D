
#include "parsing.h"



t_map	read_map(t_fd fd)
{
	t_map	result;
	char	*tmp;
	char	*join;

	tmp = "read";
	join = NULL;
	result = NULL;
	while (tmp)
	{
		tmp = get_next_line(fd);
		join = ft_strfjoin(join, tmp);
		ft_free(tmp);
		if (!join)
			break ;
	}
	result = ft_split(join, '\n');
	return (result);
}