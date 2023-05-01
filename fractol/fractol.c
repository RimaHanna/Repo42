#include "fractol.h"

void	refresh_image(t_fractal *f)
{
	mlx_destroy_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, f->width, f->height);
	f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel,
							 &f->line_length, &f->endian);
	if (!(ft_strncmp(f->name, "mandelbrot", 10)))
		mandelbrotset(f);
	else if (!(ft_strncmp(f->name, "julia", 5)))
			juliaset(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
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

void	print_string_exit(void)
{
	write(1, "WRONG PARAMETER INPUT\n", 22);
	write(1, "PLEASE TYPE:\n", 13);
	write(1, "\t\t\t'mandelbrot'\n\t\tOR\n", 21);
	write(1, "\t\t\t'julia'\n\t\tOR\n", 16);
	exit (1);
}

void	init_fractal(t_fractal f)
{
		f.mlx = mlx_init();
		f.win = mlx_new_window(f.mlx, f.width, f.height, "Rhanna");
		f.img = mlx_new_image(f.mlx, f.width, f.height);
		refresh_image(&f);
		mlx_key_hook(f.win, key_hook, &f);
		mlx_mouse_hook(f.win, mouse_hook, &f);
		mlx_hook(f.win, 17, 0, end_project, &f);
		mlx_loop(f.mlx);
}

int main(int argc, char **argv)
{
	t_fractal f;

	if (argc == 2)
	{

		if (!(ft_strncmp(argv[1], "mandelbrot", 10)) && (ft_strlen(argv[1]) == 10))
			mandelbrot_parameter(&f, "mandelbrot");
		else if (!(ft_strncmp(argv[1], "julia", 5)) && (ft_strlen(argv[1]) == 5))
			julia_parameter(&f, "julia");
		else
			print_string_exit();
		init_fractal(f);
	}
	else
		print_string_exit();
	return (0);
}
