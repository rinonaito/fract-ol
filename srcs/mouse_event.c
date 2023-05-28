/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:57:33 by rnaito            #+#    #+#             */
/*   Updated: 2023/05/26 17:05:41 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	click_on_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	ft_zoomin(t_vars *vars)
{
	double	zoom_b;
	double	zoom_a;

	zoom_b = vars->img->zoom;
	if (zoom_b == 0)
		zoom_a = 1;
	else
		zoom_a = 1.5 * zoom_b;
	vars->img->zoom = zoom_a;
}

void	ft_zoomout(t_vars *vars)
{
	double	zoom_b;
	double	zoom_a;

	zoom_b = vars->img->zoom;
	if (zoom_b < 2)
		zoom_a = 1;
	else
		zoom_a = zoom_b / 1.5;
	vars->img->zoom = zoom_a;
}

int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	double	zoom_b;

	(void)x;
	(void)y;
	zoom_b = vars->img->zoom;
	if (keycode == SCROLL_UP)
		ft_zoomin(vars);
	if (keycode == SCROLL_DOWN)
		ft_zoomout(vars);
	ft_make_img(vars->img, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}
