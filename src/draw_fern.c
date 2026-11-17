/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fern.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:25:16 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/16 11:15:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fract_ol.h"
// #include "ft_string.h"
// #include "mlx.h"
// #include <stdlib.h>
// #include <sys/types.h>

// draws the fern fractal
// old xy = 1
// new xy = 0
// x = 0
// y = 1
//
/*  See: https://en.wikipedia.org/wiki/Barnsley_fern
 *
 *
   f1	01 %
        xn + 1 = 0
        yn + 1 = 0.16 yn

   f2	85 %
        xn + 1 = 0.85 xn + 0.04 yn
        yn + 1 = −0.04 xn + 0.85 yn + 1.6

   f3	07 %
        xn + 1 = 0.2 xn − 0.26 yn
        yn + 1 = 0.23 xn + 0.22 yn + 1.6

    f4	07 %
        xn + 1 = −0.15 xn + 0.28 yn
        yn + 1 = 0.26 xn + 0.24 yn + 0.44
 *
 * interest zone is 4 by 4
*/

// static inline void	draw_loop(double point[2][2], size_t alea)
// {
// 	if (alea <= 1)
// 	{
// 		point[0][0] = 0;
// 		point[0][1] = .16 * point[1][1];
// 	}
// 	if (alea <= 86)
// 	{
// 		point[0][0] = .85 * point[1][0] + .04 * point[1][1];
// 		point[0][1] = -.04 * point[1][0] + .85 * point[1][1] + 1.6;
// 	}
// 	if (alea <= 93)
// 	{
// 		point[0][0] = .2 * point[1][0] - .26 * point[1][1];
// 		point[0][1] = .23 * point[1][0] - .22 * point[1][1] + 1.6;
// 	}
// 	else
// 	{
// 		point[0][0] = -0.15 * point[1][0] + 0.28 * point[1][1];
// 		point[0][1] = 0.26 * point[1][0] + 0.24 * point[1][1] + 0.44;
// 	}
// }
// 
// void	draw_fern(const t_context *ctx)
// {
// 	double	point[2][2];
// 	size_t	i;
// 	size_t	alea;
// 
// 	ft_memset(&point, '0', sizeof(point));
// 	i = 0;
// 	while (i < 10000)
// 	{
// 		alea = rand() % 100;
// 		ft_memcpy(&point[1], &point[0], sizeof(point[0]));
// 		draw_loop(point, alea);
// 		i++;
// 		mlx_pixel_put(ctx->mlx.mlx, ctx->mlx.win,
// 		 30 * point[0][0] + 400, 30 * point[0][1] + 400, 0x00FF00);
// 	}
// }
