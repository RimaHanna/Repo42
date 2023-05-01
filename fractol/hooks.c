#include "fractol.h"

void	key_hook_key(int keycode,t_fractal *f)
{
	if (keycode == LEFT)
	{
		f->xarrowM -= 50 / f->zoom;
		f->xarrow -= 50 / f->zoom;
	}
	else if (keycode == RIGHT)
	{
		f->xarrowM += 50 / f->zoom;
		f->xarrow += 50 / f->zoom;
	}
	else if (keycode == UP)
	{
		f->yarrowM -= 50 / f->zoom;
		f->yarrow -= 50 / f->zoom;
	}
	else if (keycode == DOWN)
	{
		f->yarrowM += 50 / f->zoom;
		f->yarrow += 50 / f->zoom;
	}
}

void	key_hook_color(int keycode, t_fractal *f)
{
	if (keycode == COLOR_PLUS_P)
		f->color += 100;
	else if (keycode == COLOR_MINUS_M)
		f->color -= 100;
}

int	key_hook(int keycode, t_fractal *f)
{
	if (keycode == ESC)
	{
		end_project(f);
		return (0);
	}
	key_hook_key(keycode, f);
	key_hook_color(keycode, f);

	if (keycode == JULIA_J)
	{
		write(1, "Julia reset!\n", 13);
		julia_parameter(f, f->name);
	}
	refresh_image(f);
	return (0);
}

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
		f->xarrow = (((f->width + 721 + f->xarrowM * 2) * f->zoom) - f->width) / 2;
		f->yarrow = (((f->height - 300 + f->yarrowM * 2) * f->zoom) - f->height) / 2;
	}
	printf("f->xarrow: %f, f->yarrow: %f\n", f->xarrow, f->yarrow);
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
		f->c.y = ((double) y / f->height * 3 - 1.5);
	//	f->zoom = 2.5;
	}
	adjust_mandelbrot(f);
	adjust_burningship(f);
    refresh_image(f);
    return (0);
}
