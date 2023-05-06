#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h> 
# include <X11/keysym.h>
# include <mlx.h>
# include <X11/X.h>

# define ESC 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define JULIA_J 106
# define COLOR_PLUS_P 112
# define COLOR_MINUS_M 109
# define ZOOM_IN_Z 122
# define ZOOM_OUT_X 120
# define MOUSE_WHEEL_ZOOM_IN 4
# define MOUSE_WHEEL_ZOOM_OUT 5
# define LEFT_MOUSE_BUTTON 1
# define RIGHT_MOUSE_BUTTON 3
# define ZOOM_FACTOR 1.3
# define MLX_ERROR 1

typedef struct s_imag
{
	double	x;
	double	y;
}			t_comp;

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
	int		width;
	int		height;
	int		iters;
	int		color;
	double	zoom;
	double	xarrow;
	double	yarrow;
	double	xmove;
	double	ymove;
	double	xi;
	double	yi;
	t_comp	c;
	double	radius;
}			t_fractal;

void	mandelbrot_parameter(t_fractal *f, char *name);
void	julia_parameter(t_fractal *f, char *name);
void	julia_parameter_plus(t_fractal *f, char *name, double c_x, double c_y);
void	burningship_parameter(t_fractal *f, char *name);

void	refresh_image(t_fractal *f);
void	mandelbrotset(t_fractal *m);
void	juliaset(t_fractal *f);
void	burningshipset(t_fractal *f);

int	my_mlx_pixel_put(t_fractal *f, int x, int y, int color);
int	end_project(t_fractal *f);
int	key_hook(int keycode, t_fractal *f);
int	mouse_hook(int keycode, int x, int y, t_fractal *f);
int	ft_strncmp(char *s1, char *s2, int n);
int	ft_strlen(char *s);
int is_number(char *s);
int	ft_str_equal(char *s1, char *s2);

#endif