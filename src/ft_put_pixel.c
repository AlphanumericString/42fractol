/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:43:27 by bgoulard          #+#    #+#             */
/*   Updated: 2024/04/29 14:51:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "mlx_structs.h"

void	ft_put_pixel(t_img *data, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < data->width && y >= 0 && y < data->height)
	{
		pxl = data->data + (y * data->size_line + x * (data->bpp / 8));
		*(unsigned int *)pxl = color;
	}
}
