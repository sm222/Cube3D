#include "render.h"

int32_t	create_rgb(int r, int g, int b)
{
	int t;

	t = 0;
	return (t << 24 | r << 16 | g << 8 | b);
}