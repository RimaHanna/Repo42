#include <stdio.h>
#include <stdlib.h>

//#include <mlx.h>
#include <X11/keysym.h>
//#include <X11/X.h>
#include "minilibx-linux/mlx.h"
# define MLX_ERROR 1
# define WIN_WID 800 
# define WIN_HEI 600 

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int handle_no_event(void *data)
{
	return (0);
}

int handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int my_mlx_pixel_put(void* addr, int x, int y, int color)
{
	char *dst;
	int line_length;
	int bits_per_pixel;

	dst = addr + (y * line_length + x * (bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return 0;
}


int main(void)
{
	t_data data;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WID, WIN_HEI, "RIMA");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	int zoom = 1;
	int width = 800;
	int height = 600;
	int iteration_max = 150;
	int i = 0;
	int x = 0;
	int y = 0;

	float xarrow = 0;
	float yarrow = 270;
	float c_r = 0;
	float c_i = 0;
	float z_r = 0;
	float z_i = 0;
	float tmp = 0;
	
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			i = 0;
			c_r = (x + xarrow)  / zoom * (0.47 + 2) / (width - 1) -2;
			c_i = (y + yarrow) / zoom * (1.12 + 1.12) / (width - 1) - 1.12;
			while ((i < iteration_max) && (z_r * z_r + z_i * z_i < 4))
			{
				tmp = z_r;
				z_r = z_r*z_r - z_i*z_i + c_r;
				z_i = 2*z_i*tmp + c_i;
				i++;
			}
			if (i == iteration_max)
			{
				printf("here\n");
				my_mlx_pixel_put(&data, (int) x, (int) y, 0xFF0000);//red
			}
			else if (i > iteration_max)
			{
				printf("here2\n");
		//		mlx_pixel_put(data.mlx_ptr, data.win_ptr, x, y, 0x000FF);
				my_mlx_pixel_put(&data, (int) x, (int) y, 0x0000FF);//red
				break;
			}
			y++;
		}
		x++;
	}
//	mlx_new_image(data.mlx_ptr, width, height);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_key_hook(data.win_ptr, &handle_input, &data);
//	mlx_mouse_hook(data.win_ptr, mouse_hook, &data);
	
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return 0;
}
