#include "parsing.h"

t_err	parsing_look_c(t_parsing *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (data->pre_map && data->pre_map[i])
	{
		j = 0;
		while (data->pre_map[i][j])
		{
			if (ft_strchr("\t\"'", data->pre_map[i][j]) != NULL)
			{
				data->err = data->pre_map[i][j];
				return (e_bad_char);
			}
			j++;
		}
		i++;
	}
	return (e_success);
}
