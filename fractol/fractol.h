#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
// # include MLX_ERROR 1

# define ESC 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65264
# define PLUS 65451
# define MINUS 65453


typedef struct	s_fractal
{
	void	*mlx;
	void	*win;
	char	*name;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	
	int	width;
	int	height;
// imaginery
	double xi;
	double yi;

	int	iters;
	int	color;
	double	zoom;
	double xarrow;
	double	yarrow;
	double	x;
	double	y;
	double	radius;
}			t_fractal;

void	mandelbrot_parameter(t_fractal *f, char *name);
int	my_mlx_pixel_put(t_fractal *f, int x, int y, int color);
void	mandelbrotset(t_fractal *m);
int	end_project(t_fractal *f);
int	key_hook(int keycode, t_fractal *f);
//int	mouse_hook(int keycode, t_fractal *f);

#endif
