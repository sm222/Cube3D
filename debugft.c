#include "cub.h"

void debug(t_cub cub)
{
	printf("C\n	------------------------\n\n");
	printf("|"RED"R"WHT" %d\n", cub.pars.texture.celing[0]);
	printf("|"GRN"G"WHT" %d\n", cub.pars.texture.celing[1]);
	printf("|"BLU"B"WHT" %d\n", cub.pars.texture.celing[2]);
	printf("\nF	------------------------\n\n");
	printf("|"RED"R"WHT" %d\n", cub.pars.texture.flore[0]);
	printf("|"GRN"G"WHT" %d\n", cub.pars.texture.flore[1]);
	printf("|"BLU"B"WHT" %d\n", cub.pars.texture.flore[2]);
	printf("\nT	-------------------------\n\n");
	printf("No %s\n", cub.pars.texture.side[e_no]);
	printf("So %s\n", cub.pars.texture.side[e_so]);
	printf("We %s\n", cub.pars.texture.side[e_we]);
	printf("Ea %s\n", cub.pars.texture.side[e_ea]);
	printf("\nM	------------------------\n\n");
	for (size_t i = 0; cub.map[i]; i++)
	{
		printf("|%s|\n", cub.map[i]);
	}
	printf("\nplayer spwan x%d y%d and is looking %c\n", cub.pars.texture.p_x, cub.pars.texture.p_y, cub.pars.texture.p_looking);
	//ft_double_sfree((void **)cub.map);
	//ft_free(cub.pars.texture.side[e_no]);
	//ft_free(cub.pars.texture.side[e_so]);
	//ft_free(cub.pars.texture.side[e_we]);
	//ft_free(cub.pars.texture.side[e_ea]);
}
