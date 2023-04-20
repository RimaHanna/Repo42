#include "fractol.h"

int	key_hook(int keycode, t_fractal *f)
{
	if (keycode == ESC)
		end_project(f);
	else if (keycode == LEFT)
		f->xarrow -= 30;
	else if (keycode == RIGHT)
		f->xarrow += 30;
	else if (keycode == UP)
		f->yarrow -= 30;
	else if (keycode == DOWN)
		f->yarrow += 30;
	else if (keycode == MINUS)
		f->color += 100;
	else if (keycode == PLUS)
		f->color -= 100;

	return 0;

}
