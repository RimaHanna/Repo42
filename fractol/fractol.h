#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include <stdlib.hi>
# include <X11/keysym.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"


typedef struct	s_fractal
{	
	int	width;
	int	height;
	int	iterations;
	int	color;
	double	zoom;
	double xarrow;
	double	yarrow;
	double x;
	double y;
	char	*name;
	void	*mlx;
	void	*win;
	void	*img;			

}	t_fractal;


#endif
