/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <rhanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:20:22 by rhanna            #+#    #+#             */
/*   Updated: 2023/05/09 10:38:10 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	my_mlx_pixel_put(t_fractal *f, int x, int y, int color)
{
	char	*dst;

	dst = f->addr + (y * f->line_length + x
			* (f->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}

void	mandelbrot_parameter(t_fractal *f, char *name)
{
	f->zoom = 1;
	f->width = 800;
	f->height = 600;
	f->iters = 80;
	f->color = 0xccf1ff;
	f->xarrow = 0;
	f->yarrow = 100;
	f->xmove = 0;
	f->ymove = 0;
	f->name = name;
}

void	julia_parameter(t_fractal *f, char *name)
{
	f->width = 800;
	f->height = 600;
	f->c.x = -0.7;
	f->c.y = 0.27015;
	f->radius = 3;
	f->iters = 120;
	f->zoom = 3;
	f->xarrow = 0;
	f->yarrow = 0;
	f->xmove = 0;
	f->ymove = 0;
	f->xi = 0;
	f->yi = 0;
	f->color = 13431795;
	f->name = name;
}

void	burningship_parameter(t_fractal *f, char *name)
{
	f->zoom = 0.37;
	f->width = 800;
	f->height = 600;
	f->iters = 150;
	f->color = 16779015;
	f->xarrow = -100;
	f->yarrow = -150;
	f->xmove = 0;
	f->ymove = 0;
	f->name = name;
}

void	julia_parameter_plus(t_fractal *f, char *name, double c_x, double c_y)
{
	f->width = 800;
	f->height = 600;
	f->c.x = c_x;
	f->c.y = c_y;
	f->radius = 3;
	f->iters = 120;
	f->zoom = 3;
	f->xarrow = 0;
	f->yarrow = 0;
	f->xmove = 0;
	f->ymove = 0;
	f->xi = 0;
	f->yi = 0;
	f->color = 13431795;
	f->name = name;
}