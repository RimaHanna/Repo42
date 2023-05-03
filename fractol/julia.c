#include "fractol.h"

t_comp	add(t_comp a, t_comp b)
{
	t_comp	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

t_comp	sqr(t_comp a)
{
	t_comp	c;

	c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * a.x * a.y;
	return (c);
}

t_comp	mappoint(t_fractal *f, double x, double y)
{
	t_comp	c;
	double		l;

	if (f->width < f->height)
		l = f->height * f->zoom;
	else
		l = f->width * f->zoom;
	x += f->xi ;
	y += f->yi ;
	c.x = 2 * f->radius * (x - f->width / 2) / l;
	c.y = 2 * f->radius * (y - f->height / 2) / l;
	return (c);
}

void	juliaset(t_fractal *f)
{
	int		i;
	t_comp	z0;
	t_comp	z1;

	f->xi = 0;
	while (++f->xi <= f->width)
	{
		f->yi = 0;
		while (++f->yi <= f->height)
		{
			z0 = mappoint(f, f->xi - (f->width / 2) + f->xarrow,
					 f->yi - (f->height / 2) + f->yarrow);
			i = 0;
			while (i++ <= f->iters)
			{
				z1 = add(sqr(z0), f->c);
				if (z1.x * z1.x + z1.y * z1.y > f->radius * f->radius)
				{
					my_mlx_pixel_put(f, f->xi, f->yi, f->color * i);
					break ;
				}
				z0 = z1;
			}
		}
	}
}