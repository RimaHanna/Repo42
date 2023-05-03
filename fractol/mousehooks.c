#include "fractol.h"

/**
 * @details Re-centers the Mandelbrot fractal
 * When Mandelbrot fractal renders, it takes 0,0 as origin,
 * so zooming will put the center of the fractal at fractal_width / 2, 
 * which does not coincide with the window's center.
 * So it needs to be displaced.
 * @param {t_fractal *} pointer to the fractal
*/
void adjust_mandelbrot(t_fractal *f)
{
    if (!(ft_strncmp(f->name, "mandelbrot", 10)))
	{
		f->xarrow = (((f->width + f->xarrowM * 2) * f->zoom) - f->width) / 2;
		f->yarrow = (((f->height + 200 + f->yarrowM * 2) * f->zoom) - f->height) / 2;
	}
}

void adjust_burningship(t_fractal *f)
{
    if (!(ft_strncmp(f->name, "burningship", 11)))
	{
		f->xarrow = (((f->width + f->xarrowM * 2) * f->zoom) - f->width) / 2 + (((400 - f->xarrowM)) * f->zoom);
		f->yarrow = (((f->height + f->yarrowM * 2) * f->zoom) - f->height) / 2 + ((100 - f->yarrowM) * f->zoom);
	}
}

int	mouse_hook(int keycode, int x, int y, t_fractal *f)
{
	if (x == y)
		return (0);
    if (keycode == MOUSE_WHEEL_ZOOM_IN )
	{
       f->zoom *= ZOOM_FACTOR;
		if(f->iters < 150)
			f->iters++;
    }
    else if (keycode == MOUSE_WHEEL_ZOOM_OUT)
    {
		if(f->iters > 80)
			f->iters--;
        f->zoom /= ZOOM_FACTOR;
    }
	else if (keycode == LEFT_MOUSE_BUTTON && !ft_strncmp(f->name, "julia", 5))
	{
		f->c.x = ((double) x / f->width * 4 - 2);
		f->c.y = ((double) y / f->height * 2 - 1.5);
		f->color += 10;
	}
	adjust_mandelbrot(f);
	adjust_burningship(f);
    refresh_image(f);
    return (0);
}