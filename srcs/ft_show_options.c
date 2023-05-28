/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:58:24 by rnaito            #+#    #+#             */
/*   Updated: 2023/05/26 17:54:50 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_show_options1(int argc)
{
	ft_printf(">> ERROR with 1st parameter\n");
	if (argc < 2)
	{
		ft_printf("You can choose which type of fractol to ");
		ft_printf("appear on the window.\n");
	}
	else
		ft_printf("Invalid parameter.\n");
	ft_printf("Plese retry with the following options:)\n-------------\n");
	ft_printf("1: mandelbrot\n2: julia\n--------------\n\n");
}

void	ft_show_options2(int argc)
{
	ft_printf(">> ERROR with 2nd parameter\n");
	if (argc < 3)
		ft_printf("2nd parameter is for your choise of the colour pallet.\n");
	else
		ft_printf("Invalid parameter.\n");
	ft_printf("Give a number between 1 to 4 as the 2nd parameter.\n\n");
}

void	ft_show_options3(int argc)
{
	ft_printf(">> ERROR with 3rd parameter\n");
	if (argc < 4)
	{
		ft_printf("In case you have selected \"julia set\",\nyou need to");
		ft_printf(" give one more parameter to the program.\n");
	}
	else
		ft_printf("Invalid parameter\n");
	ft_printf("Give a number between 1 to 3 as the 3rd parameter:)\n\n");
}
