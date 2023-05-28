/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:59:46 by rnaito            #+#    #+#             */
/*   Updated: 2023/05/26 15:59:56 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_mv_view(int keycode, t_vars *vars)
{
	if (keycode == RIGHT)
		vars->slide_hor -= 0.1 / vars->img->zoom;
	if (keycode == LEFT)
		vars->slide_hor += 0.1 / vars->img->zoom;
	if (keycode == DOWN)
		vars->slide_var -= 0.1 / vars->img->zoom;
	if (keycode == UP)
		vars->slide_var += 0.1 / vars->img->zoom;
	ft_make_img(vars->img, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

void	ft_change_colour(int keycode, t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (keycode == OPEN)
			vars->img->pallet[i] += 30;
		if (keycode == CLOSE)
			vars->img->pallet[i] -= 30;
		i++;
	}
	ft_make_img(vars->img, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

int	keypress(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode >= RIGHT && keycode <= UP)
		ft_mv_view(keycode, vars);
	if (keycode == OPEN || keycode == CLOSE)
		ft_change_colour(keycode, vars);
	return (0);
}
