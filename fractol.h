/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 10:07:06 by rnaito            #+#    #+#             */
/*   Updated: 2023/05/14 16:57:49 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <math.h>
#include <stdlib.h>

typedef struct s_complex {
	double real;
	double img;
}				t_complex;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	*img;
	int		height;
	int		width;
	char	*name;
}				t_vars;

void	my_mlx_pixel_put(t_data *img_addr, int x, int y, int color);
int		close(int keycode, t_vars *vars);
int		mouse_hook(int	keycode, int x, int y, t_vars *vars);
void	ft_make_mandelbrot_img(t_data *img_addr, int win_width, int win_height, int	zoom);

#endif