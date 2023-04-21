#include "fractol.h"


void	mandelbrotset(t_fractal	*m)
{
	int	x;
	int	y;
	int	i;
	double	z_r;
	double	z_i;
	double	tmp;

	x = 0;
	while (x++ < m->width)
	{
		y = 0;
		while (y++ < m->height)
		{
			i = 0;
			z_r = 0;
			z_i = 0;
			m->xi = (x + m->xarrow)  / m->zoom * (0.47 + 2) / (m->width - 1) -2;
			m->yi = (y + m->yarrow) / m->zoom * (1.12 + 1.12) / (m->width - 1) - 1.12;
			while (i++ < m->iters)
			{
				tmp = z_r;
				z_r = z_r*z_r - z_i*z_i + m->xi;
				z_i = 2*z_i*tmp + m->yi;
				if (((z_r * z_r) + (z_i * z_i)) > 4) 
				{
					my_mlx_pixel_put(m, (int) x, (int) y, m->color * i);
					break ;
				}
			}
		}
	}
}
