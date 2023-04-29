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
	else if (keycode == COLOR_PLUS_P)
		f->color += 100;
	else if (keycode == COLOR_MINUS_M)
		f->color -= 100;
	refresh_image(f);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_fractal *f)
{
	if (x == y)
		return (0);
    if (keycode == MOUSE_WHEEL_ZOOM_IN || keycode == LEFT_MOUSE_BUTTON)
	{
       f->zoom *= ZOOM_FACTOR;
		if(f->iters < 150)
			f->iters++;
    }
    else if (keycode == MOUSE_WHEEL_ZOOM_OUT || keycode == RIGHT_MOUSE_BUTTON)
    {
		if(f->iters > 80)
			f->iters--;
        f->zoom /= ZOOM_FACTOR;
    }
/*
	int j = mlx_mouse_get_pos(f->mlx, f->win, &x, &y);
	x = 300;
	y = 300;
	printf("j: %d\tx: %d\ty: %d\tzoom: %f\n", j, x, y, f->zoom);
	int xo = f->pos_x + x - f->width / 2;
	int yo = y - f->height / 2;
	int mxo = (xo * (f->zoom - 1));
	int myo = (yo * (f->zoom - 1));
	f->pos_x = mxo;
	f->pos_y = myo;
	f->xarrow = ((((f->width + f->xarrowM * 2) * f->zoom) - f->width) / 2) + mxo;
	f->yarrow = ((((f->height + 200 + f->yarrowM * 2) * f->zoom) - f->height) / 2) + myo;
	printf("xo: %d\tyo: %d\tmxo: %d\tmyo: %d\t\n", xo, yo, mxo, myo);
	printf("xarrow: %f\tyarrow: %f\n", f->xarrow, f->yarrow);
*/
	f->xarrow = (((f->width + f->xarrowM * 2) * f->zoom) - f->width) / 2;
	f->yarrow = (((f->height + 200 + f->yarrowM * 2) * f->zoom) - f->height) / 2;
    refresh_image(f);
    return (0);
}
