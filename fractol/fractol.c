#include "fractol.h"


int	my_mlx_pixel_put(t_fractal *f, int x, int y, int color)
{
	char	*dst;

	dst = f->addr + (y * f->line_length + x
				 * (f->bits_per_pixel / 8));
	*(unsigned int *)dst = color;

	return (0);
}

int	end_project(t_fractal *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int main()
{
	t_fractal f;

	mandelbrot_parameter(&f, "mandelbrot");
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, f.width, f.height, "Rhanna");
	f.img = mlx_new_image(f.mlx, f.width, f.height);
	f.addr = mlx_get_data_addr(f.img, &f.bits_per_pixel,
							 &f.line_length, &f.endian);
	mandelbrotset(&f);
	my_mlx_pixel_put(&f, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(f.mlx, f.win, f.img, 0, 0);
	mlx_key_hook(f.win, key_hook, &f);
//	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_hook(f.win, 17, 0, end_project, &f);
	mlx_loop(f.mlx);
}
