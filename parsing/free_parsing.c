# include "parsing.h"

/// @brief only use at the end of the game to free the texture and map
/// @param data input
/// @return e_susses or e_badarg
int	free_parinsg(t_parsing *data)
{
	int			i;
	t_texture	*tmp;

	if (!data)
		return (e_bad_args);
	tmp = &data->texture;
	i = 0;
	while (i < 4)
		tmp->side[i] = ft_free(tmp->side[i]);
	i = 0;
	data->map = (char **)ft_double_sfree((void **)data->map);
	return (e_success);
}