#include "parsing.h"

t_err	parsing_err(t_parsing *data, t_err err)
{
	if (err < e_success)
		ft_printf(2, "%oError\n", NULL);
	if (err == e_empty_map)
		ft_printf(2, "%oCub3D: "RED"%s"WHT" is empty\n", NULL, data->map_name);
	if (err == e_malloc_f)
		ft_printf(2, "%oCub3D: "RED"malloc fail"WHT"\n", NULL);
	if (err == e_bad_char)
		ft_printf(2, "%oCub3D: "RED"bad char"WHT"\n", NULL);
	return (err);
}