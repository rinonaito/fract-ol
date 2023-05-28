/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:56:26 by rnaito            #+#    #+#             */
/*   Updated: 2023/05/26 17:12:15 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_strcmp_fractol(char *input, char *option)
{
	size_t	i;

	i = 0;
	if (input == NULL || option == NULL)
		return (0);
	while (input[i] != '\0')
	{
		if (input[i] != option[i])
			return (0);
		i++;
	}
	if (option[i] == '\0')
		return (1);
	return (0);
}

int	ft_check_arg1(int argc, char *input, t_vars *vars)
{
	if (ft_strcmp_fractol(input, "mandelbrot") == 1)
	{
		vars->img->img_type = 1;
		vars->name = "Mandelbrot";
		return (1);
	}
	else if (ft_strcmp_fractol(input, "julia") == 1)
	{
		vars->img->img_type = 2;
		vars->name = "Julia";
		return (2);
	}
	else if (ft_strcmp_fractol(input, "burningship") == 1)
	{
		vars->img->img_type = 3;
		vars->name = "Burning Ship";
		return (3);
	}
	else
	{
		ft_show_options1(argc);
		ft_show_options2(argc);
		return (0);
	}
}

int	ft_check_arg2(int argc, char *input, t_data *img)
{
	if (ft_strcmp_fractol(input, "1") == 1)
		ft_get_pastel_pallet(img);
	else if (ft_strcmp_fractol(input, "2") == 1)
		ft_get_wisteria_pallet(img);
	else if (ft_strcmp_fractol(input, "3") == 1)
		ft_get_sunset_pallet(img);
	else if (ft_strcmp_fractol(input, "4") == 1)
		ft_get_burning_pallet(img);
	else
	{
		ft_show_options2(argc);
		if (img->img_type == 2)
			ft_show_options3(argc);
		return (0);
	}
	return (1);
}

int	ft_check_arg(int argc, char **argv, t_vars *vars)
{
	if (ft_check_arg1(argc, argv[1], vars) == 0)
		return (1);
	if (ft_check_arg2(argc, argv[2], vars->img) == 0)
		return (1);
	if (vars->img->img_type == 2)
	{
		if (ft_get_julia_type(argv[3], vars->img, argc) == 0)
			return (1);
	}
	return (0);
}
