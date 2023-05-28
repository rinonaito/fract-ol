/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_determine_colour.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:04:15 by rnaito            #+#    #+#             */
/*   Updated: 2023/05/25 22:07:23 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_gradient(int color1, int color2, double t)
{
	int	r;
	int	g;
	int	b;

	r = (1 - t) * (color1 & RED) + t * (color2 & RED);
	g = (1 - t) * (color1 & GREEN) + t * (color2 & GREEN);
	b = (1 - t) * (color1 & BLUE) + t * (color2 & BLUE);
	return ((r & RED) | (g & GREEN) | (b & BLUE));
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr +(y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_determine_colour(t_data *img, int x, int y, int depth)
{
	int	border[7];
	int	i;

	i = 0;
	while (i < 7)
	{
		border[i] = MAX_ITR / 7 * i;
		i++;
	}
	if (depth == 0)
		my_mlx_pixel_put(img, x, y, BLACK);
	i = 1;
	while (i < 7)
	{
		if (depth > border[i - 1] && depth <= border[i])
			my_mlx_pixel_put(img, x, y,
				color_gradient(img->pallet[i - 1], img->pallet[i],
					(double)(depth - border[i - 1])
					/ (border[i] - border[i - 1])));
		i++;
	}
	if (depth > border[i - 1])
		my_mlx_pixel_put(img, x, y, img->pallet[i - 1]);
}
