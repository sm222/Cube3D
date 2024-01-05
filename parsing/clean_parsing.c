#include "parsing.h"

short	clean_parsing(t_parsing *data)
{
	int	i;

	i = 0;
	data->pre_map = (t_map)ft_double_sfree((void **)data->pre_map);
	data->map = (t_map)ft_double_sfree((void **)data->map);
	while (i < 4)
	{
		data->texture.side[i] = ft_free(data->texture.side[i]);
		i++;
	}
	return (1);
}
