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
	i = 0;
	while (j < 3)
	{
		i += skip_space(s);
		tmp = ft_atoi(s + i);
		if (tmp > 255)
			return (e_bad_number);
		color[j] = tmp;
		i += skip_to(s + i, ',');
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
	data->texture.cf[c] = true;
	while (s[i] && (ft_isdigit(s[i]) || s[i] == ',' || s[i] == ' '))
	{
		if (s[i] == ',')
			vergul++;
		if (vergul > 2 || (s[i] == ',' && s[i + 1] == ','))
			break ;
		i++;
	}
	if (i == ft_strlen(s))
	{
		if (c == 0)
			return (get_nbr(s + 1, data->texture.celing));
		if (c == 1)
			return (get_nbr(s + 1, data->texture.flore));
	}
	return (e_bad_char);
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
		ft_printf(2, "Error\n");
		ft_printf(2, "%oCub: invalid char after data\n", NULL);
		*err = e_bad_char;
		return (NULL);
	}
	new = ft_strndup(s + i, j);
	*err = e_success;
	return (new);
}
