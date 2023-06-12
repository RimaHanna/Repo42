/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <rhanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:52:09 by rhanna            #+#    #+#             */
/*   Updated: 2023/05/09 10:53:28 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	refresh_image(t_fractal *f)
{
	mlx_destroy_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, f->width, f->height);
	f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel,
			&f->line_length, &f->endian);
	if (!(ft_strncmp(f->name, "m", 1)))
		mandelbrotset(f);
	else if (!(ft_strncmp(f->name, "j", 1)))
		juliaset(f);
	else if (!(ft_strncmp(f->name, "b", 1)))
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
	write(1, "\t\t\t'm' for mandelbrot\n\t\tOR\n", 27);
	write(1, "\t\t\t'j' for julia\n\t\tOR\n", 22);
	write(1, "\t\t\t'b' for burningship\n\n", 24);
	write(1, "\ttry to add only two float parameter to julia", 45);
	write(1, " and give it a try for a new fractol\n\n", 38);
	write(1, "THANK YOU!!! :) \n", 17);
	write(1, "\t--------------------------------------\n", 40);
	exit (1);
}

void	parameter_check(t_fractal *f, int ac, char **av)
{
	if ((ac == 2) && ft_str_equal(av[1], "m"))
		mandelbrot_parameter(f, "mandelbrot");
	else if ((ac == 2) && ft_str_equal(av[1], "j"))
		julia_parameter(f, "julia");
	else if ((ac == 2) && ft_str_equal(av[1], "b"))
		burningship_parameter(f, "burningship");
	else if ((ac == 4) && ft_str_equal(av[1], "j")
		&& (is_number(av[2])) && (is_number(av[3])))
		julia_parameter_plus(f, "julia", atof(av[2]), atof(av[3]));
	else
		print_string_exit();
}

int	main(int ac, char **av)
{
	t_fractal	f;

	parameter_check(&f, ac, av);
	f.mlx = mlx_init();
	if (f.mlx == NULL)
		return (MLX_ERROR);
	f.win = mlx_new_window(f.mlx, f.width, f.height, "Rhanna");
	if (f.win == NULL)
	{
		free (f.win);
		return (MLX_ERROR);
	}
	f.img = mlx_new_image(f.mlx, f.width, f.height);
	refresh_image(&f);
	mlx_key_hook(f.win, key_hook, &f);
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_hook(f.win, 17, 0, end_project, &f);
	mlx_loop(f.mlx);
	return (0);
}