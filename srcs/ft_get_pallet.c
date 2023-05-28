/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pallet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:52:15 by rnaito            #+#    #+#             */
/*   Updated: 2023/05/25 22:05:21 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_get_sunset_pallet(t_data *img)
{
	img->pallet[0] = 0x000091AD;
	img->pallet[1] = 0x00455E89;
	img->pallet[2] = 0x005C4D7D;
	img->pallet[3] = 0x00723C70;
	img->pallet[4] = 0x00892B64;
	img->pallet[5] = 0x00A01A58;
	img->pallet[6] = 0x00B7094C;
}

void	ft_get_pastel_pallet(t_data *img)
{
	img->pallet[0] = 0x00FFE8DD;
	img->pallet[1] = 0x00FFD2CD;
	img->pallet[2] = 0x00FFBCCA;
	img->pallet[3] = 0x00F4A9D3;
	img->pallet[4] = 0x00D59DE5;
	img->pallet[5] = 0x009D98F6;
	img->pallet[6] = 0x000099FF;
}

void	ft_get_wisteria_pallet(t_data *img)
{
	img->pallet[0] = 0x00604CF9;
	img->pallet[1] = 0x008F5EF7;
	img->pallet[2] = 0x00B174F6;
	img->pallet[3] = 0x00CB8BF6;
	img->pallet[4] = 0x00E0A4F7;
	img->pallet[5] = 0x00F2BEFA;
	img->pallet[6] = 0x00FFD9FF;
}

void	ft_get_burning_pallet(t_data *img)
{
	img->pallet[0] = 0x000A102B;
	img->pallet[1] = 0x00182547;
	img->pallet[2] = 0x00748DB3;
	img->pallet[3] = 0x00931E30;
	img->pallet[4] = 0x00ED3E13;
	img->pallet[5] = 0x00FECA1F;
	img->pallet[6] = 0x00FFFFFF;
}
