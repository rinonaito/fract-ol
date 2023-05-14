/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:06:46 by rnaito            #+#    #+#             */
/*   Updated: 2023/05/14 17:11:31 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	close(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	mouse_hook(int	keycode, int x, int y, t_vars *vars)
{
	static double	zoom;

	(void)x;
	(void)y;
	if (keycode == 4)
		zoom += 0.5;
	if (keycode == 5)
	{
		if (zoom > 1)
			zoom -= 0.5;
	}
	ft_make_mandelbrot_img(vars->img, vars->width, vars->height, zoom);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}

// t_vars *vars
// (*vars).
//  vars->

// t_vars **vars
// (**vars).
//  (*vars)->
