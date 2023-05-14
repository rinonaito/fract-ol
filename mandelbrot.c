/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:05:37 by rnaito            #+#    #+#             */
/*   Updated: 2023/05/14 16:51:08 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_determine_colour(t_data *img_addr, int x, int y, int depth)
{
	if (depth <= 0)
		my_mlx_pixel_put(img_addr, x, y, 0x00FFFFFF);
	else if (depth < 10)
		my_mlx_pixel_put(img_addr, x, y, 0x0087CEFA);
	else if (depth < 20)
		my_mlx_pixel_put(img_addr, x, y, 0x004169E1);
	else if (depth < 30)
		my_mlx_pixel_put(img_addr, x, y, 0x00483D8B);
	else if (depth < 40)
		my_mlx_pixel_put(img_addr, x, y, 0x00CC6699);
	else if (depth < 50)
		my_mlx_pixel_put(img_addr, x, y, 0x09966660);
}

static int	ft_judge_depth(double r, double i)
{
	t_complex z[50];
	int idx;
	double	early_real;
	double	early_img;

	z[0].real= 0;
	z[0].img= 0;
	idx = 1;
	while (idx < 50)
	{
		early_real = z[idx - 1].real;
		early_img = z[idx - 1].img;
		if (early_real * early_real + early_img * early_img > 4)
			return (idx);
		z[idx].real = early_real * early_real - early_img * early_img + r;   
		z[idx].img = early_real * early_img + early_real * early_img + i;	
		idx++;
	}
	return (0);
}

void	ft_make_mandelbrot_img(t_data *img_addr, int win_width, int win_height, int zoom)
{
	double	x;
	double	y;
	double	r;
	double	i;
	int		depth;

	x = 0;
	y = 0;
	while (y < win_height)
	{
		while (x < win_width)
		{
			r = (x - win_width / 2) / (320 * zoom);
			i = (win_height / 2 - y) / (320 * zoom);
			depth = ft_judge_depth(r, i);
			ft_determine_colour(img_addr, x, y, depth);
			x++;
		}
		x = 0;
		y++;
	}
}