#include "fractol.h"

void	key_hook_key(int keycode,t_fractal *f)
{
	if (keycode == LEFT)
	{
		f->xmove -= 50 / f->zoom;
		f->xarrow -= 50 / f->zoom;
	}
	else if (keycode == RIGHT)
	{
		f->xmove += 50 / f->zoom;
		f->xarrow += 50 / f->zoom;
	}
	else if (keycode == UP)
	{
		f->ymove -= 50 / f->zoom;
		f->yarrow -= 50 / f->zoom;
	}
	else if (keycode == DOWN)
	{
		f->ymove += 50 / f->zoom;
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