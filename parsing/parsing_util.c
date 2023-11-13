
#include "parsing.h"


size_t	skip_space(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] && s[i] == ' ')
		i++;
	return (i);
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
	data->texture.seling[0] = 0;
	data->texture.seling[1] = 0;
	data->texture.seling[2] = 0;
	data->texture.cf[0] = false;
	data->texture.cf[1] = false;
	in[4][0] = 0;
}