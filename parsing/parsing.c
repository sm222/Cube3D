
#include "parsing.h"

static t_err	look_all(t_parsing *data)
{
	t_err		rvalue;

	rvalue = 0;
	rvalue += parsing_err(data, read_map(data));
	if (rvalue < e_success)
		return (rvalue);
	rvalue += parsing_err(data, parsing_look_c(data));
	if (rvalue < e_success)
		return (rvalue);
	
	return (e_success);
}

t_map	parsing(char *arg)
{
	t_parsing	data;
	t_err		rvalue;

	rvalue = 0;
	ft_bzero(&data, sizeof(t_parsing));
	if (!arg)
		return (NULL);
	data.map_name = arg;
	if (open_file(&data, arg) == -1)
		return (NULL);
	if (look_all(&data) < e_success)
		return (NULL);
	return (data.map);
}
