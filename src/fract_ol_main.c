/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:32:54 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/16 12:29:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "fract_ol_types.h"
#include "mlx.h"
#include <stdlib.h>

static int	ft_get_color(t_context *ctx, size_t x, size_t y)
{
	int	(*fractol_drawers[FRACTAL_ERROR])(const t_context *, int, int);

	fractol_drawers[MANDELBROT] = pixel_mandelbrot;
	fractol_drawers[JULIA] = pixel_julia;
	fractol_drawers[BURNINGSHIP] = pixel_burningship;
	fractol_drawers[TRICORN] = pixel_tricorn;
	fractol_drawers[NEWTON] = pixel_newton;
	if (ctx->fractal >= FRACTAL_ERROR || ctx->fractal == BARNFERN)
		exit(1);
	return (fractol_drawers[ctx->fractal](ctx, x, y));
}

/*
 * if (ctx->fractal == BARNFERN)
 *		return (draw_fern(ctx), (void)mlx_put_image_to_window \	
 *		(ctx->mlx.mlx, ctx->mlx.win, ctx->mlx.img, 0, 0));
*/
void	ft_draw_fractal(t_context *ctx)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < ctx->mlx.height)
	{
		x = 0;
		while (x < ctx->mlx.width)
		{
			ft_put_pixel(ctx->mlx.img, x, y, ft_get_color(ctx, x, y));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(ctx->mlx.mlx, ctx->mlx.win, ctx->mlx.img, 0, 0);
}

void	ft_camera_init(t_camera *cam)
{
	if (cam->zoom == 0)
		cam->zoom = 1;
	if (cam->move_speed == 0)
		cam->move_speed = 1;
}

int	fract_ol_main(int ac, char **av, t_context *ctx)
{
	(void)ac;
	(void)av;
	ft_mlx_init(&ctx->mlx, ctx);
	ft_camera_init(&ctx->camera);
	ft_draw_fractal(ctx);
	mlx_loop(ctx->mlx.mlx);
	ft_mlx_destroy(&ctx->mlx);
	return (EXIT_SUCCESS);
}
