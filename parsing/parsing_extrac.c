# include "parsing.h"

static t_err	get_nbr(char *s, t_color color[3])
{
	size_t	i;
	size_t	j;
	int		tmp;

	j = 0;
	i = skip_space(s);
	if (s[i] == ',')
	{
		read_and_set_err_p(-1, e_add);
		return (e_inva_arg);
	}
	while (j < 3)
	{
		tmp = ft_atoi(s + i);
		if (tmp > 255)
		{
			read_and_set_err_p(1, e_add);
			return (e_bad_number);
		}
		color[j] = tmp;
		i += skip_to(s + i, ',') + 1;
		read_and_set_err_p(skip_to(s + i, ','), e_add);
		j++;
	}
	return (e_success);
}

t_err	extract_line_nbr(char *s, t_parsing *data, short c)
{
	size_t		i;
	short		vergul;

	i = 1;
	vergul = 0;
	while (s[i] && (ft_isdigit(s[i]) || s[i] == ',' || s[i] == ' '))
	{
		if (s[i] == ',')
		{
			vergul++;
			if (look_next(s, i + 1) || vergul > 2)
				return (e_bad_char);
		}
		i++;
		read_and_set_err_p(1, e_add);
	}
	data->texture.cf[c] = true;
	if (i == ft_strlen(s) && vergul == 2 && look_last_number(s, i))
	{
		if (c == 0)
			return (get_nbr(s + 1, data->texture.celing));
		if (c == 1)
			return (get_nbr(s + 1, data->texture.flore));
	}
	return (e_inva_arg);
}

char	*extract_line_txt(char *s, t_err *err, size_t len)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = NULL;
	i = 2;
	j = 0;
	while (s && i < len && s[i] == ' ')
		i++;
	while (s && i+ j < len && s[i + j] != ' ')
		j++;
	if (look_at_end(s + i + j, len))
	{
		while (s[j + i] && s[j + i] == ' ')
			j++;
		read_and_set_err_p(i + j -1, e_add);
		*err = e_inva_data_end;
		return (NULL);
	}
	new = ft_strndup(s + i, j);
	*err = e_success;
	if (!new)
		*err = e_inva_arg;
	return (new);
}
