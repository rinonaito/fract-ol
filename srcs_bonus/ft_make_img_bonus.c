/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_img_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:58:50 by rnaito            #+#    #+#             */
/*   Updated: 2023/05/26 15:59:00 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	ft_make_mandelbrot(double r, double i)
{
	int			idx;
	double		early_real;
	double		early_img;
	t_complex	z[MAX_ITR];

	z[0].real = 0;
	z[0].img = 0;
	idx = 1;
	while (idx < MAX_ITR)
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

static int	ft_make_julia(double r, double i, double cr, double ci)
{
	int			idx;
	double		early_real;
	double		early_img;
	t_complex	z[MAX_ITR];

	z[0].real = r;
	z[0].img = i;
	idx = 1;
	while (idx < MAX_ITR)
	{
		early_real = z[idx - 1].real;
		early_img = z[idx - 1].img;
		if (early_real * early_real + early_img * early_img > 4)
			return (idx);
		z[idx].real = early_real * early_real - early_img * early_img + cr;
		z[idx].img = early_real * early_img + early_real * early_img + ci;
		idx++;
	}
	return (0);
}

static int	ft_make_burningship(double r, double i)
{
	int			idx;
	double		early_real;
	double		early_img;
	t_complex	z[MAX_ITR];

	z[0].real = 0;
	z[0].img = 0;
	idx = 1;
	while (idx < MAX_ITR)
	{
		early_real = fabs(z[idx - 1].real);
		early_img = -1 * fabs(z[idx - 1].img);
		if (early_real * early_real + early_img * early_img > 4)
			return (idx);
		z[idx].real = early_real * early_real - early_img * early_img + r;
		z[idx].img = early_real * early_img + early_real * early_img + i;
		idx++;
	}
	return (0);
}

static double	ft_get_depth(t_data *img, double r, double i)
{
	double	depth;

	if (img->img_type == 1)
		depth = ft_make_mandelbrot(r, i);
	if (img->img_type == 2)
		depth = ft_make_julia(r, i, img->c.real, img->c.img);
	if (img->img_type == 3)
		depth = ft_make_burningship(r, i);
	return (depth);
}

void	ft_make_img(t_data *img, t_vars *vars)
{
	double	x;
	double	y;
	double	r;
	double	i;
	int		depth;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			r = (x - WIDTH / 2) / (SCALE * vars->img->zoom) + vars->slide_hor;
			i = (HEIGHT / 2 - y) / (SCALE * vars->img->zoom) + vars->slide_var;
			depth = ft_get_depth(img, r, i);
			ft_determine_colour(img, x, y, depth);
			x++;
		}
		x = 0;
		y++;
	}
}
