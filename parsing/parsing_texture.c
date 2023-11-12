
#include "parsing.h"

static size_t	skip_space(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

static t_err	read_line_texture(char *line, t_extract_t *var, t_parsing *data)
{
	t_index	dex;
	(void)data;

	ft_bzero(&dex, sizeof(t_index));
	dex.i += skip_space(line);
	if (line[dex.i])
	{
		while (dex.j < 4)
		{
			if (ft_strncmp(line + dex.i, var->name[dex.j], 2) == 0 \
			&& !var->side[dex.j])
			{
				var->side[dex.j] = true;
				return (e_success);
			}
			else if (ft_strncmp(line + dex.i, var->name[dex.j], 2) == 0 \
			&& var->side[dex.j])
				return (e_double_card);
			dex.j++;
		}
	}
	else
		return (e_empty_line);
	return (e_success);
}

static void	set_value(char in[5][3])
{
	ft_memmove(in[0], "NO", 3);
	ft_memmove(in[1], "SO", 3);
	ft_memmove(in[2], "WE", 3);
	ft_memmove(in[3], "EA", 3);
	in[4][0] = 0;
}

t_err	extract_texture(t_parsing *data)
{
	t_extract_t	var;

	ft_bzero(&var, sizeof(t_extract_t));
	set_value(var.name);
	while (data->pre_map && data->pre_map[var.line])
	{
		if (read_line_texture(data->pre_map[var.line], &var, data) == e_double_card)
			printf("[]%s\n", data->pre_map[var.line]);
		var.line++;
	}
	return (0);
}
