#include "parsing.h"

/// @brief use to clean memorry if somting fail in parsing
/// @param data main struc of parsing
/// @return return success
short	clean_parsing(t_parsing *data)
{
	int	i;

	i = 0;
	data->pre_map = (t_map)ft_double_sfree((void **)data->pre_map);
	while (i < 4)
	{
		data->texture.side[i] = ft_free(data->texture.side[i]);
		i++;
	}
	return (e_success);
}
