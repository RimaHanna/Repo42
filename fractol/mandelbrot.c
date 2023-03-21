

void mandelbrot(void)
{
	float x1 = -2.1;
	float x2 = 0.6;
	float y1 = -1.2;
	float y2 = 1.2;
	int zoom = 100;
	int iteration_max = 50;
	int i = 0;
	int x = 0;
	int y = 0;

	float image_x = (x2 - x1) * zoom;
	float image_y = (y2 - y1) * zoom;
	float c_r = 0;
	float c_i = 0;
	float z_r = 0;
	float z_i = 0;
	float tmp = 0;

	while (x < image_x)
	{
		y = 0;
		while (y < image_y)
		{
			c_r = x / zoom + x1;
			c_i = y / zoom + y1;
			while ((i < iteration_max) && (z_r * z_r + z_i * z_i < 4))
			{
				tmp = z_r;
				z_r = z_r*z_r - z_i*z_i + c_r;
				z_i = 2*z_i*tmp + c_i;
				i++;
			}
			if (i == iteration_max)
				//draw image
				break;
			y++;
		}
		x++;
	}
	
}
