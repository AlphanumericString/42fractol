/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_fractals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:42:32 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/17 12:55:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "fract_ol_types.h"
#include "ft_extended.h"
#include <math.h>
#include <sys/types.h>

// draws the newton fractal
int	pixel_newton(const t_context *restrict ctx, int x, int y)
{
	size_t	i;
	double	scalled_pts[4];
	double	calc_val;

	i = 0;
	x += ctx->camera.x * ctx->camera.zoom;
	y += ctx->camera.y * ctx->camera.zoom;
	scalled_pts[0] = (x / (double) ctx->mlx.height) * 2.47 / ctx->camera.zoom \
		- 2.0 / ctx->camera.zoom;
	scalled_pts[1] = (y / (double) ctx->mlx.width) * 2.24 / ctx->camera.zoom - \
		1.12 / ctx->camera.zoom;
	scalled_pts[2] = scalled_pts[0];
	scalled_pts[3] = scalled_pts[1];
	while (pow(scalled_pts[2], 2) + pow(scalled_pts[3], 2) <= pow(2, 2)
		&& i < ctx->it)
	{
		calc_val = scalled_pts[2];
		scalled_pts[2] = pow(scalled_pts[2], 3) - 3 * scalled_pts[2] * \
			pow(scalled_pts[3], 2) + scalled_pts[0];
		scalled_pts[3] = 3 * pow(calc_val, 2) * scalled_pts[3] - \
			pow(scalled_pts[3], 3) + scalled_pts[1];
		i++;
	}
	return (i * (ctx->it != i) * ft_irange(i, 0, ctx->it, 0xFFFFFF));
}

// draws the tricorn fractal
int	pixel_tricorn(const t_context *restrict ctx, int x, int y)
{
	size_t	i;
	double	scalled_pts[4];
	double	calc_val;

	i = 0;
	x += ctx->camera.x * ctx->camera.zoom;
	y += ctx->camera.y * ctx->camera.zoom;
	scalled_pts[0] = (x / (double) ctx->mlx.height) * 2.47 / ctx->camera.zoom \
		- 2.0 / ctx->camera.zoom;
	scalled_pts[1] = (y / (double) ctx->mlx.width) * 2.24 / ctx->camera.zoom - \
		1.12 / ctx->camera.zoom;
	scalled_pts[2] = scalled_pts[0];
	scalled_pts[3] = scalled_pts[1];
	while (pow(scalled_pts[2], 2) + pow(scalled_pts[3], 2) <= pow(2, 2)
		&& i < ctx->it)
	{
		calc_val = scalled_pts[2];
		scalled_pts[2] = pow(scalled_pts[2], 2) - pow(scalled_pts[3], 2)
			+ scalled_pts[0];
		scalled_pts[3] = -2 * calc_val * scalled_pts[3] + scalled_pts[1];
		i++;
	}
	if (i == ctx->it)
		return (0);
	return (ft_irange(i, 0, ctx->it, 0xFFFFFF));
}

// draws the burning ship fractal
int	pixel_burningship(const t_context *restrict ctx, int x, int y)
{
	size_t	i;
	double	scalled_pts[4];
	double	calc_val;

	i = 0;
	x += ctx->camera.x * ctx->camera.zoom;
	y += ctx->camera.y * ctx->camera.zoom;
	scalled_pts[0] = (x / (double) ctx->mlx.height) * 2.47 / ctx->camera.zoom \
		- 2.0 / ctx->camera.zoom;
	scalled_pts[1] = (y / (double) ctx->mlx.width) * 2.24 / ctx->camera.zoom - \
		1.12 / ctx->camera.zoom;
	scalled_pts[2] = scalled_pts[0];
	scalled_pts[3] = scalled_pts[1];
	while (pow(scalled_pts[2], 2) + pow(scalled_pts[3], 2) <= pow(2, 2)
		&& i < ctx->it)
	{
		calc_val = scalled_pts[2];
		scalled_pts[2] = pow(scalled_pts[2], 2) - pow(scalled_pts[3], 2)
			+ scalled_pts[0];
		scalled_pts[3] = 2 * fabs(calc_val * scalled_pts[3]) + scalled_pts[1];
		i++;
	}
	if (i == ctx->it)
		return (0);
	return (ft_irange(i, 0, ctx->it, 0xFFFFFF));
}

int	pixel_julia(const t_context *restrict ctx, int x, int y)
{
	size_t	i;
	double	scalled_pts[4];
	double	calc_val;

	i = 0;
	x += ctx->camera.x * ctx->camera.zoom;
	y += ctx->camera.y * ctx->camera.zoom;
	scalled_pts[0] = (x / (double) ctx->mlx.height) * 2.47 / ctx->camera.zoom \
		- 2.0 / ctx->camera.zoom;
	scalled_pts[1] = (y / (double) ctx->mlx.width) * 2.24 / ctx->camera.zoom - \
		1.12 / ctx->camera.zoom;
	scalled_pts[2] = scalled_pts[0];
	scalled_pts[3] = scalled_pts[1];
	while (pow(scalled_pts[2], 2) + pow(scalled_pts[3], 2) <= 4 && i < ctx->it)
	{
		calc_val = scalled_pts[2];
		scalled_pts[2] = pow(scalled_pts[2], 2) - pow(scalled_pts[3], 2)
			+ ctx->start_c;
		scalled_pts[3] = 2 * calc_val * scalled_pts[3] + ctx->start_z;
		i++;
	}
	if (i == ctx->it)
		return (0);
	return (ft_irange(i, 0, ctx->it, 0xFFFFFF));
}

int	pixel_mandelbrot(const t_context *restrict ctx, int x, int y)
{
	size_t	i;
	double	scalled_pts[4];
	double	calc_val;

	i = 0;
	calc_val = 0;
	x += ctx->camera.x * ctx->camera.zoom;
	y += ctx->camera.y * ctx->camera.zoom;
	scalled_pts[0] = (x / (double) ctx->mlx.height) * 2.47 / ctx->camera.zoom \
		- 2.0 / ctx->camera.zoom;
	scalled_pts[1] = (y / (double) ctx->mlx.width) * 2.24 / ctx->camera.zoom \
		- 1.12 / ctx->camera.zoom;
	scalled_pts[2] = scalled_pts[0];
	scalled_pts[3] = scalled_pts[1];
	while (pow(scalled_pts[2], 2) + pow(scalled_pts[3], 2) <= 4 && i < ctx->it)
	{
		calc_val = scalled_pts[2];
		scalled_pts[2] = pow(scalled_pts[2], 2) - pow(scalled_pts[3], 2)
			+ scalled_pts[0];
		scalled_pts[3] = 2 * calc_val * scalled_pts[3] + scalled_pts[1];
		i++;
	}
	return ((i != ctx->it) * ft_irange(i, 0, ctx->it, 0xFFFFFF));
}
