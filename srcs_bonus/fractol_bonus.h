/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:13:42 by rnaito            #+#    #+#             */
/*   Updated: 2023/05/26 17:46:58 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

///// LIBRARY
# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"

///// DEFINITION
# define WIDTH (1200)
# define HEIGHT (800)

# define RED (0xff0000)
# define GREEN (0xff00)
# define BLUE (0xff)
# define BLACK (0x00000000)

# define MAX_ITR (100)

# define KEY_PRESS (2)
# define ON_DESTROY (17)

# define SCROLL_UP (4)
# define SCROLL_DOWN (5)

# define ESC (53)

# define RIGHT (123)
# define LEFT (124)
# define UP (126)
# define DOWN (125)

# define OPEN (30)
# define CLOSE (33)

# define SCALE (240)

///// STRUCT
typedef struct s_complex {
	double	real;
	double	img;
}			t_complex;

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			pallet[7];
	int			img_type;
	t_complex	c;
	double		zoom;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	*img;
	double	slide_hor;
	double	slide_var;
	char	*name;
}				t_vars;

///// FUNCTION
//ft_check_arg.c
int		ft_check_arg(int argc, char **argv, t_vars *vars);
int		ft_check_arg1(int argc, char *input, t_vars *vars);
int		ft_check_arg2(int argc, char *input, t_data *img);
int		ft_strcmp_fractol(char *input, char *option);

//ft_get_pallet.c
void	ft_get_sunset_pallet(t_data *img);
void	ft_get_pastel_pallet(t_data *img);
void	ft_get_wisteria_pallet(t_data *img);
void	ft_get_burning_pallet(t_data *img);

//ft_get_julia_type.c
int		ft_get_julia_type(char	*input, t_data *img, int argc);

//ft_show_options.c
void	ft_show_options1(int argc);
void	ft_show_options2(int argc);
void	ft_show_options3(int argc);

//ft_make_img.c
void	ft_make_img(t_data *img_addr, t_vars *vars);

//ft_determine_colour.c
void	ft_determine_colour(t_data *img, int x, int y, int depth);
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);

//key_event.c
void	ft_mv_view(int keycode, t_vars *vars);
int		keypress(int keycode, t_vars *vars);

//mouse_event.c
int		mouse_hook(int keycode, int x, int y, t_vars *vars);
void	ft_determine_slide(int x, int y, t_vars *vars, double zoom_b);
int		click_on_destroy(t_vars *vars);

#endif