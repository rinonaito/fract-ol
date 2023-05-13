#include <mlx.h>
#include <math.h>
#include <complex.h>
#include <stdio.h>

typedef struct s_complex {
	double real;
	double img;
}				t_complex;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_is_mandelbrot(double r, double i)
{
	t_complex z[30];
	int idx;
	double	early_real;
	double	early_img;

	z[0].real= 0;
	z[0].img= 0;
	idx = 1;
	while (idx < 30)
	{
		early_real = z[idx - 1].real;
		early_img = z[idx - 1].img;
		if (early_real * early_real + early_img * early_img > 4)
			return (0);
		z[idx].real = early_real * early_real - early_img * early_img + r;   
		z[idx].img = early_real * early_img + early_real * early_img + i;	
		idx++;
	}
	return (1);
}

void	ft_print_mandelbrot(t_data *img_addr, int win_width, int win_height)
{
	double	x;
	double	y;
	double	r;
	double	i;
	int		is_mandelbrot;

	x = 0;
	y = 0;
	while (y < win_height)
	{
		while (x < win_width)
		{
			r = (x - win_width / 2) / 320;
			i = (win_height / 2 - y) / 320;
			is_mandelbrot = ft_is_mandelbrot(r, i);
			if (is_mandelbrot == 0)
				my_mlx_pixel_put(img_addr, x, y, 0x000000FF);
			x++;
		}
		x = 0;
		y++;
	}

}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		window_height;
	int		window_width;

	mlx = mlx_init();
	window_width = 1920;
	window_height = 1080;
	mlx_win = mlx_new_window(mlx, window_width, window_height, "Mandelbrot Set");
	img.img = mlx_new_image(mlx, window_width, window_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	ft_print_mandelbrot(&img, window_width, window_height);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}