/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:00:06 by rnaito            #+#    #+#             */
/*   Updated: 2023/05/26 18:36:02 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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

void	ft_determine_slide(int x, int y, t_vars *vars, double zoom_b)
{
	double	zoom_a;
	double	slide_var_a;
	double	slide_var_b;
	double	slide_hor_a;
	double	slide_hor_b;

	zoom_a = vars->img->zoom;
	slide_hor_b = vars->slide_hor;
	slide_hor_a = (x - WIDTH / 2) * (1 / (SCALE * zoom_b)
			- 1 / (SCALE * zoom_a)) + slide_hor_b;
	slide_var_b = vars->slide_var;
	slide_var_a = (HEIGHT / 2 - y) * (1 / (SCALE * zoom_b)
			- 1 / (SCALE * zoom_a)) + slide_var_b;
	vars->slide_var = slide_var_a;
	vars->slide_hor = slide_hor_a;
}

int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	double	zoom_b;

	zoom_b = vars->img->zoom;
	if (keycode == SCROLL_UP)
		ft_zoomin(vars);
	if (keycode == SCROLL_DOWN)
		ft_zoomout(vars);
	ft_determine_slide(x, y, vars, zoom_b);
	ft_make_img(vars->img, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}
