#include "fractol.h"

double fabs_positive(double x)
{
    if (x < 0) 
        return (-x);
    else 
        return (x);
}
void	miniburning(int x, int y, t_fractal *f)
{
	int		i;
	double	zr;
	double	zi;
	double	tmp;

	i = 0;
	f->xi = (x + f->xarrow) / f->zoom * (2) / (f->width) - 2;
	f->yi = (y + f->yarrow) / f->zoom * (2) / (f->width) - 1;
	zr = 0;
	zi = 0;
	while (++i < f->iters)
	{
		tmp = zr;
		zr = fabs_positive(zr*zr - zi*zi + f->xi);
		zi = fabs_positive(2*zi*tmp + f->yi);
		if (((zr * zr) + (zi * zi)) > 4) 
		{
			my_mlx_pixel_put(f, (int) x, (int) y, f->color * (i));
			break ;
		}
	}
}

void	burningshipset(t_fractal *f)
{
	int	x;
	int	y;

	x = 0;
	while (x < f->width)
	{
		y = 0;
		while (y < f->height)
		{	
			miniburning(x, y, f);
			y++;
		}
		x++;
	}
}