

#include "parsing.h"

static t_err	read_line_map(char *s, size_t i)
{
	size_t	j;

	j = skip_space(s);
	if (j == ft_strlen(s))
		return (e_empty_line);
	while (s && s[j])
	{
		if (ft_strchr("01 NSEW", s[j]))
			j++;
		else
		{
			printf("[%zu]\n%s\n", i + 1, s);
			ft_print_err_len(j++);
		}
	}
	return (e_success);
}

t_err	extract_map(t_parsing *data)
{
	t_err	err;
	size_t	i;
	
	err = 0;
	i = 0;
	while (data->pre_map[i + data->i])
	{
		err = read_line_map(data->pre_map[i + data->i], i + data->i);
		i++;
	}
	return (err);
}