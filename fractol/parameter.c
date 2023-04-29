#include "fractol.h"

void	mandelbrot_parameter(t_fractal *f, char *name)
{
	f->zoom = 1;
	f->width = 800;
	f->height = 600;
	f->iters = 80;
	f->color = 0xccf1ff;
	f->xarrow = 0;
	f->yarrow = 100;
	f->xarrowM = 0;
	f->yarrowM = 0;
//	f->x = 0;
//	f->y = 0;
	f->name = name;
}
