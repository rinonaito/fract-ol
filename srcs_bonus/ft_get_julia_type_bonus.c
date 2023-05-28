/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_julia_type_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:57:06 by rnaito            #+#    #+#             */
/*   Updated: 2023/05/26 15:57:10 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_get_julia_type(char	*input, t_data *img, int argc)
{
	if (ft_strcmp_fractol(input, "1") == 1)
	{
		img->c.real = -0.7;
		img->c.img = 0.3;
	}
	else if (ft_strcmp_fractol(input, "2") == 1)
	{
		img->c.real = -0.8;
		img->c.img = 0.15;
	}
	else if (ft_strcmp_fractol(input, "3") == 1)
	{
		img->c.real = -0.3;
		img->c.img = -0.63;
	}
	else
	{
		ft_show_options3(argc);
		return (0);
	}
	return (1);
}
