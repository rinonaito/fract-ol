/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:06:58 by rnaito            #+#    #+#             */
/*   Updated: 2023/05/14 17:11:00 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
				return (1);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	return (1);
}

#include <stdio.h>

int	main()
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.width = 1920;
	vars.height = 1080;
	vars.name = "Mandelbrot set";
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, vars.name);
	img.img = mlx_new_image(vars.mlx, vars.width, vars.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	ft_make_mandelbrot_img(&img, vars.width, vars.height, 1);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	vars.img = &img;
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}