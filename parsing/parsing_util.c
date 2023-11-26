
#include "parsing.h"

int	look_all_texture(t_texture *in)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (in->cf[0])
		i++;
	if (in->cf[1])
		i++;
	while (j < 4)
	{
		if (in->side[j])
			i++;
		j++;
	}
	return (i);
}

size_t	skip_to(t_str *str, char c)
{
	if (!str)
		return (0);
	while (str->s && str->i < str->len && str->s[str->i] != c)
		str->i++;
	return (str->i);
}

size_t	skip_while(t_str *str, char c)
{
	if (!str)
		return (0);
	while (str->s && str->i < str->len && str->s[str->i] == c)
		str->i++;
	return (str->i);
}

void	set_value(char in[5][5], t_parsing *data)
{
	ft_memmove(in[0], "NO ", 4);
	ft_memmove(in[1], "SO ", 4);
	ft_memmove(in[2], "WE ", 4);
	ft_memmove(in[3], "EA ", 4);
	data->texture.side[e_no] = NULL;
	data->texture.side[e_so] = NULL;
	data->texture.side[e_we] = NULL;
	data->texture.side[e_ea] = NULL;
	data->texture.flore[0] = 0;
	data->texture.flore[1] = 0;
	data->texture.flore[0] = 0;
	data->texture.celing[0] = 0;
	data->texture.celing[1] = 0;
	data->texture.celing[2] = 0;
	data->texture.cf[0] = false;
	data->texture.cf[1] = false;
	in[4][0] = 0;
}
