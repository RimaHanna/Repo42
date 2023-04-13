#include "fractol.h"

void	mandelbrot_parameter(t_fractal *fractal, char *name)
{
	fractal->zoom = 1;
	fractal->width = 1280;
	fractal->height = 720;
	fractal->iteration = 150;
	fractal->color = 0xccf1ff;
	fractal->xarrow = 0;
	fractal->yarrow = ;
	fractal->c_r = ;
	fractal->c_i = ;
	fractal->name = name;
}
