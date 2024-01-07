#include "parsing.h"

/// @brief use to set a error to a distance and return the t_err code
/// @param len len to set
/// @param code err code to return
/// @return t_err pass in code
t_err	set_err_and_return_code(size_t len, t_err code)
{
	read_and_set_err_p(len, e_set);
	return (code);
}

/// @brief use to print
/// @param data main struct of parsing
/// @param err error code 
/// @return the error code from 'err'
t_err	parsing_err(t_parsing *data, t_err err)
{
	if (err < e_success)
		ft_printf(2, "%oError\n", NULL);
	if (err == e_empty_map)
		ft_printf(2, "%oCub3D: "RED"%s"WHT" is empty\n", NULL, data->map_name);
	if (err == e_malloc_f)
		ft_printf(2, "%oCub3D: "RED"malloc fail"WHT"\n", NULL);
	if (err == e_bad_char)
	{
		ft_printf(2, "%oCub3D: "RED"bad char at line %u"WHT"\n", \
		NULL, data->errh);
		ft_printf(2, "%o%s\n", NULL, data->err_line);
		ft_print_err_len(data->errw - 1);
	}
	return (err);
}
