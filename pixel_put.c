/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:06:17 by rnaito            #+#    #+#             */
/*   Updated: 2023/05/14 14:02:06 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *img_addr, int x, int y, int color)
{
	char	*dst;

	dst = img_addr->addr + (y * img_addr->line_length + x * (img_addr->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

