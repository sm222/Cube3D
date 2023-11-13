
#include "parsing.h"

static t_err	look_data_fc(char *s, t_extract_t *var, t_parsing *data)
{
	if (ft_strncmp(s, "C ", 2) == 0 && !data->texture.cf[0])
	{
		extract_line_nbr(s, var, data, 0);
		return (e_success);
	}
	else if (ft_strncmp(s, "C ", 2) == 0 && data->texture.cf[0])
	{
		//
		return (e_double_card);
	}
	else if (ft_strncmp(s, "F ", 2) == 0 && !data->texture.cf[0])
	{
		extract_line_nbr(s, var, data, 1);
		return (e_success);
	}
	else if (ft_strncmp(s, "F ", 2) == 0 && data->texture.cf[0])
	{
		//
		return (e_double_card);
	}
	return (e_bad_char);
}

static t_err	look_data_str(char *s, t_extract_t *var, t_parsing *data)
{
	size_t	j;

	j = 0;
	while (j < 4)
	{
		if (ft_strncmp(s, var->name[j], 3) == 0 && \
			!data->texture.side[j])
			{
				data->texture.side[j] = extract_line_txt(s, &var->err);
				return (e_success);
			}
		else if (ft_strncmp(s, var->name[j], 3) == 0 && \
			data->texture.side[j])
				return (e_double_card);
		j++;
	}
	return (look_data_fc(s, var, data));
}

static t_err	read_line_texture(char *line, t_extract_t *var, t_parsing *data)
{
	size_t	i;
	t_err	err;

	i = skip_space(line);
	if (line[i])
	{
		err = look_data_str(line + i, var, data);
	}
	else
		return (e_empty_line);
	return (err);
}

t_err	extract_texture(t_parsing *data)
{
	t_extract_t	var;

	ft_bzero(&var, sizeof(t_extract_t));
	set_value(var.name, data);
	while (data->pre_map && data->pre_map[var.line])
	{
		var.err = read_line_texture(data->pre_map[var.line], &var, data);
		if (var.err == e_bad_char || var.err == e_double_card)
		{
			printf("[%zu]%s\n", var.line, data->pre_map[var.line]);
		}
		var.line++;
	}
	printf("no%s\n", data->texture.side[e_no]);
	printf("so%s\n", data->texture.side[e_so]);
	printf("we%s\n", data->texture.side[e_we]);
	printf("ea%s\n", data->texture.side[e_ea]);
	return (0);
}
