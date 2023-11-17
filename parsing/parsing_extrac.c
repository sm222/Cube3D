# include "parsing.h"

static short	look_at_end(char *end)
{
	size_t	i;

	i = 0;
	if (!end || !end[0])
		return (0);
	while (end[i] && end[i] == ' ')
		i++;
	if (!end[i])
		return (0);
	return (1);
}

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

static short	look_next(char *s, size_t i)
{
	while (s && s[i])
	{
		if (s[i] == ',')
			return (1);
		else if (ft_isdigit(s[i]))
			return (0);
		else
			i++;
	}
	return (0);
}

static short	look_last_number(char *s, size_t i)
{
	while (i > 0)
	{
		if (ft_isdigit(s[i]))
			return (1);
		if (s[i] == ',')
			return (0);
		i--;
	}
	return (0);
}

t_err	extract_line_nbr(char *s, t_parsing *data, short c)
{
	size_t		i;
	short		vergul;

	i = 1;
	vergul = 0;
	data->texture.cf[c] = true;
	while (s[i] && (ft_isdigit(s[i]) || s[i] == ',' || s[i] == ' '))
	{
		if (s[i] == ',')
		{
			vergul++;
			if (look_next(s, i + 1) || vergul > 2 )
				return (e_bad_char);
		}
		i++;
		read_and_set_err_p(1, e_add);
	}
	if (i == ft_strlen(s) && vergul == 2 && look_last_number(s , i))
	{
		if (c == 0)
			return (get_nbr(s + 1, data->texture.celing));
		if (c == 1)
			return (get_nbr(s + 1, data->texture.flore));
	}
	return (e_inva_arg);
}

char	*extract_line_txt(char *s, t_err *err)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = NULL;
	i = 2;
	j = 0;
	while (s && s[i] && s[i] == ' ')
		i++;
	while (s && s[i + j] && s[i + j] != ' ')
		j++;
	if (look_at_end(s + i + j))
	{
		while (s[j + i] && s[j + i] == ' ')
			j++;
		read_and_set_err_p(i + j -1, e_add);
		*err = e_inva_data_end;
		return (NULL);
	}
	new = ft_strndup(s + i, j);
	*err = e_success;
	return (new);
}
