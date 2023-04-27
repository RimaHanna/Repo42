#include "fractol.h"

int	key_hook(int keycode, t_fractal *f)
{
	//printf("keycode %d\n", keycode);
	if (keycode == ESC)
		end_project(f);
	else if (keycode == LEFT)
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
	else if (keycode == MINUS)
		f->color += 100;
	else if (keycode == PLUS)
		f->color -= 100;
/*	else if (keycode == ZOOM_IN_Z)
	{
        f->zoom *= ZOOM_FACTOR;
		if(f->iters < 150)
			f->iters++;
    }
	else if (keycode == ZOOM_OUT_X)
    {
		if(f->iters > 80)
			f->iters--;
        f->zoom /= ZOOM_FACTOR;
    }
	f->xarrow = (((f->width + f->xarrowM * 2) * f->zoom) - f->width) / 2;
	f->yarrow = (((f->height + 200 + f->yarrowM * 2) * f->zoom) - f->height) / 2;*/
	refresh_image(f);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_fractal *f)
{
	if (x == y)
		return (0);
    if (keycode == MOUSE_WHEEL_ZOOM_IN)
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
	f->xarrow = (((f->width + f->xarrowM * 2) * f->zoom) - f->width) / 2;
	f->yarrow = (((f->height + 200 + f->yarrowM * 2) * f->zoom) - f->height) / 2;
    refresh_image(f);
    return (0);
}
