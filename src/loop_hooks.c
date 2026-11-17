/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:34:25 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/17 11:05:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "fract_ol_types.h"
#include "ft_string.h"
#include "mlx.h"
#include <stdbool.h>
#include <stdlib.h>

static const char	*ft_fractal_name(t_fractal fractal)
{
	const char	*fractal_str[] = {
	[MANDELBROT] = "Mandelbrot",
	[JULIA] = "Julia",
	[BURNINGSHIP] = "Burningship",
	[TRICORN] = "Tricorn",
	[BARNFERN] = "Barnfern",
	[NEWTON] = "Newton",
	[FRACTAL_ERROR] = "FRACTAL_ERROR"
	};

	return (fractal_str[fractal]);
}

static void	ft_putnbrf_fd(double n, int fd, int precision)
{
	int		integer;
	double	decimal;
	int		mult;

	mult = 1;
	integer = (int)n;
	decimal = n - integer;
	ft_putnbr_fd(integer, fd);
	ft_putchar_fd('.', fd);
	while (precision--)
		mult *= 10;
	if (decimal < 0)
		decimal *= -1;
	ft_putnbr_fd((int)(decimal * mult), fd);
}

static void	log_context(t_context *ctx)
{
	static t_context	prev_ctx = {0};

	if (ft_memcmp(&prev_ctx, ctx, sizeof(t_context)) == 0)
		return ;
	ft_memcpy(&prev_ctx, ctx, sizeof(t_context));
	ft_putstr_fd("fractal: ", 1);
	ft_putendl_fd(ft_fractal_name(ctx->fractal), 1);
	ft_putstr_fd("x: ", 1);
	ft_putnbrf_fd(ctx->camera.x, 1, 2);
	ft_putstr_fd(" y: ", 1);
	ft_putnbrf_fd(ctx->camera.y, 1, 2);
	ft_putstr_fd(" zoom: ", 1);
	ft_putnbrf_fd(ctx->camera.zoom, 1, 2);
	ft_putstr_fd(" it: ", 1);
	ft_putnbr_fd(ctx->it, 1);
	ft_putstr_fd(" move_speed: ", 1);
	ft_putnbr_fd(ctx->camera.move_speed, 1);
	ft_putstr_fd(" move_held: ", 1);
	ft_putnbr_fd(ctx->camera.move_held, 1);
	ft_putstr_fd(" zoom_held: ", 1);
	ft_putnbr_fd(ctx->camera.zoom_held, 1);
	ft_putstr_fd(" update_screen: ", 1);
	ft_putnbr_fd(ctx->update_screen, 1);
	ft_putstr_fd("\n", 1);
}

int	loop_hook(t_context *ctx)
{
	if (ctx->logmode == true)
		log_context(ctx);
	mlx_clear_window(ctx->mlx.mlx, ctx->mlx.win);
	if (ctx->update_screen == true)
	{
		ft_draw_fractal(ctx);
		ctx->update_screen = false;
	}
	mlx_put_image_to_window(ctx->mlx.mlx, ctx->mlx.win, ctx->mlx.img, 0, 0);
	return (EXIT_SUCCESS);
}
