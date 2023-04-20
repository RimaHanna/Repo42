#include "fractol.h"

void	mandelbrot_parameter(t_fractal *f, char *name)
{
	f->zoom = 1;
	f->width = 1280;
	f->height = 720;
	f->iters = 150;
	f->color = 0xccf1ff;
	f->xarrow = 0;
	f->yarrow = 0;
	f->x = 0;
	f->y = 0;
	f->name = name;
}
