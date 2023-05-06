#include "fractol.h"

void	refresh_image(t_fractal *f)
{
	mlx_destroy_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, f->width, f->height);
	f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel,
							 &f->line_length, &f->endian);
	if (!(ft_strncmp(f->name, "mandelbrot", 1)))
		mandelbrotset(f);
	else if (!(ft_strncmp(f->name, "julia", 1)))
		juliaset(f);
	else if (!(ft_strncmp(f->name, "burningship", 1)))
		burningshipset(f);
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
	write(1, "\t\t\t'burningship'\n", 17);
	write(1, "\t--------------------------------------\n", 40);
	exit (1);
}

int main(int ac, char **av)
{
	t_fractal f;

	if ((ac == 2) && ft_str_equal(av[1], "m"))
		mandelbrot_parameter(&f, "mandelbrot");
	else if ((ac == 2) && ft_str_equal(av[1], "j"))
		julia_parameter(&f, "julia");
	else if ((ac == 2) && ft_str_equal(av[1], "b"))
		burningship_parameter(&f, "burningship");
	else if ((ac == 4) && ft_str_equal(av[1], "j")
			&& (is_number(av[2])) && (is_number(av[3])))
		julia_parameter_plus(&f, "julia", atof(av[2]), atof(av[3]));
	else
		print_string_exit();
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, f.width, f.height, "Rhanna");
	f.img = mlx_new_image(f.mlx, f.width, f.height);
	refresh_image(&f);
	mlx_key_hook(f.win, key_hook, &f);
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_hook(f.win, 17, 0, end_project, &f);
	mlx_loop(f.mlx);
	return (0);
}
/*
int main(int ac, char **av)
{
	t_fractal f;

	if (ac == 2)
	{
		if (!(ft_strncmp(av[1], "m", 1)) && (ft_strlen(av[1]) == 1))
			mandelbrot_parameter(&f, "mandelbrot");
		else if (!(ft_strncmp(av[1], "j", 1)) && (ft_strlen(av[1]) == 1))
			julia_parameter(&f, "julia");
		else if (!(ft_strncmp(av[1], "b", 1)) && (ft_strlen(av[1]) == 1))
			burningship_parameter(&f, "burningship");
		else
			print_string_exit();
		f.mlx = mlx_init();
		f.win = mlx_new_window(f.mlx, f.width, f.height, "Rhanna");
		f.img = mlx_new_image(f.mlx, f.width, f.height);
		refresh_image(&f);
		mlx_key_hook(f.win, key_hook, &f);
		mlx_mouse_hook(f.win, mouse_hook, &f);
		mlx_hook(f.win, 17, 0, end_project, &f);
		mlx_loop(f.mlx);
	}
	else
		print_string_exit();
	return (0);
} */
