#include "fractol.h"

void	minimandel (int x, int y, t_fractal *f)
{
	int		i;
	double	zr;
	double	zi;
	double	tmp;

	i = 0;
	f->xi = (x + f->xarrow) / f->zoom * (0.48 + 2) / (f->width) - 2;
	f->yi = (y + f->yarrow) / f->zoom * (1.14 + 1.14) / (f->width) - 1.14;
	zr = f->xi;
	zi = f->yi;
	while (++i < f->iters)
	{
		tmp = zr;
		zr = zr*zr - zi*zi + f->xi;
		zi = 2*zi*tmp + f->yi;
		if (((zr * zr) + (zi * zi)) > 4) 
		{
			my_mlx_pixel_put(f, (int) x, (int) y, f->color * (i));
			break ;
		}
	}
}

void	mandelbrotset(t_fractal	*f)
{
	int	x;
	int	y;

	x = 0;
	while (x < f->width)
	{
		y = 0;
		while (y < f->height)
		{	
			minimandel(x, y, f);
			y++;
		}
		x++;
	}
}
