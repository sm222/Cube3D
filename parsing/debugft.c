
#include "parsing.h"

void	print_debug(t_parsing *data)
{
	printf("no%s\n", data->texture.side[e_no]);
	printf("so%s\n", data->texture.side[e_so]);
	printf("we%s\n", data->texture.side[e_we]);
	printf("ea%s\n", data->texture.side[e_ea]);
	printf("C %d,%d,%d\n", data->texture.celing[0], data->texture.celing[1], data->texture.celing[2]);
	printf("F %d,%d,%d\n", data->texture.flore[0], data->texture.flore[1], data->texture.flore[2]);
}