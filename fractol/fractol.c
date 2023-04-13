int main(int argc, char **argv)
{
	t_fractal f;

	if (argc == 2)
	{
		// check parameter
	}
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, f.width, f.height, "Rhanna");
	f.img = mlx_new_image(f.mlx, f.width, f.height);
}
