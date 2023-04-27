#include "fractol.h"

void	minimandel (int x, int y, t_fractal *f)
{
	int		i;
	double	z_r;
	double	z_i;
	double	tmp;

	i = 0;
	f->xi = (x + f->xarrow) / f->zoom * (0.48 + 2) / (f->width) - 2;
	f->yi = (y + f->yarrow) / f->zoom * (1.14 + 1.14) / (f->width) - 1.14;
	z_r = f->xi;
	z_i = f->yi;
	while (++i < f->iters)
	{
		tmp = z_r;
		z_r = z_r*z_r - z_i*z_i + f->xi;
		z_i = 2*z_i*tmp + f->yi;
		if (((z_r * z_r) + (z_i * z_i)) > 4) 
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

// mandelbrot complete function
/*
void	mandelbrotset(t_fractal	*f)
{
	int	x;
	int	y;
	int	i;
	double	z_r;
	double	z_i;
	double	tmp;

	x = 0;
	while (x < f->width)
	{
		y = 0;
		while (y < f->height)
		{	
			i = 0;
			f->xi = (x + f->xarrow) / f->zoom * (0.48 + 2) / (f->width) - 2;
			f->yi = (y + f->yarrow) / f->zoom * (1.14 + 1.14) / (f->width) - 1.14;
			z_r = f->xi;
			z_i = f->yi;
			while (++i < f->iters)
			{
				tmp = z_r;
				z_r = z_r*z_r - z_i*z_i + f->xi;
				z_i = 2*z_i*tmp + f->yi;
				if (((z_r * z_r) + (z_i * z_i)) > 4) 
				{
					my_mlx_pixel_put(f, (int) x, (int) y, f->color * (i));
					break ;
				}
			}
			y++;
		}
		x++;
	}
}
*/