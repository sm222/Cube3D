#include "parsing.h"

static short	set_space(t_map map, size_t const len, size_t const max_len)
{
	map[0] = ft_calloc(max_len + 2, sizeof(char));
	if (!map[0])
		return (e_malloc_f);
	map[len - 2] = ft_calloc(max_len + 2, sizeof(char));
	if (!map[len - 2])
	{
		ft_free(map[0]);
		return (e_malloc_f);
	}
	ft_memset(map[0], ' ', max_len - 1);
	ft_memset(map[len - 2], ' ', max_len - 1);
	return (e_success);
}

static short	add_space_to_line(t_map old, t_map new, const size_t max)
{
	size_t	i;
	size_t	len;
	char	*tmp;

	i = 0;
	while (old && old[i])
	{
		len = max - ft_strlen(old[i] + 1);
		tmp = ft_calloc(len + 1, sizeof(char));
		if (!tmp)
			return (e_malloc_f);
		ft_memset(tmp, ' ', len);
		ft_printf(NO_PRINT, "%o %s%s", &new[i + 1], old[i], tmp);
		tmp = ft_free(tmp);
		if (!new[i + 1])
			return (e_malloc_f);
		i++;
	}
	return (e_success);
}

t_map	make_safe_copy(t_map map, const size_t max_len)
{
	size_t	len;
	t_map	new_map;

	len = ft_strlen_double(map) + 3;
	new_map = ft_calloc(len + 1, sizeof(char *));
	if (set_space(new_map, len, max_len + 3) < e_success)
	{
		ft_printf(2, "%oError\nCub3D: malloc fail\n", NULL);
		ft_free(new_map);
		return (NULL);
	}
	if (add_space_to_line(map, new_map, max_len) < e_success)
	{
		new_map[len - 2] = ft_free(new_map[len - 2]);
		new_map = (char **)ft_double_sfree((void **)new_map);
		ft_printf(2, "%oError\nCub3D: malloc fail\n", NULL);
	}
	return (new_map);
}
