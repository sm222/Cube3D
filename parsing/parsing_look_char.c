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
			if (ft_strchr("	'\"", \
			data->pre_map[i][j]) != NULL)
			{
				data->err = data->pre_map[i][j];
				data->errh = i + 1;
				data->errw = j + 1;
				data->err_line = data->pre_map[i];
				return (e_bad_char);
			}
			j++;
		}
		i++;
	}
	return (e_success);
}
