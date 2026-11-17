/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:11:02 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/06 08:37:25 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "fract_ol_types.h"
#include "ft_string.h"
#include "mlx.h"
#include <X11/X.h>

int	ft_mlx_destroy(t_mlx *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
		mlx_destroy_display(mlx->mlx);
	ft_free(&mlx->mlx);
	return (EXIT_SUCCESS);
}

static void	default_win_param(t_mlx *mlx)
{
	mlx->width = WIN_WIDTH;
	mlx->height = WIN_HEIGHT;
}

static void	setup_hooks(t_context *ctx)
{
	mlx_hook(ctx->mlx.win, KeyRelease, KeyReleaseMask, key_hook_release, ctx);
	mlx_hook(ctx->mlx.win, KeyPress, KeyPressMask, key_hook, ctx);
	mlx_hook(ctx->mlx.win, DestroyNotify, NoEventMask, close_hook, ctx);
	mlx_hook(ctx->mlx.win, ButtonPress, ButtonPressMask, mouse_hook_click, ctx);
	mlx_hook(ctx->mlx.win, MotionNotify, PointerMotionMask,
		mouse_hook_act, ctx);
	mlx_hook(ctx->mlx.win, ButtonRelease, ButtonReleaseMask,
		mouse_hook_release, ctx);
	mlx_loop_hook(ctx->mlx.mlx, loop_hook, ctx);
}

int	ft_mlx_init(t_mlx *mlx, t_context *ctx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (ft_putstr_fd("Error: mlx_init failed\n", 2), EXIT_FAILURE);
	default_win_param(mlx);
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, VERSION);
	if (!mlx->win)
		return (ft_putstr_fd("Error: mlx_new_window failed\n", 2),
			EXIT_FAILURE);
	mlx->img = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	if (!mlx->img)
		return (ft_putstr_fd("Error: mlx_new_image failed\n", 2), EXIT_FAILURE);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	if (!mlx->addr)
		return (ft_putstr_fd("Error: mlx_get_data_addr failed\n", 2),
			EXIT_FAILURE);
	setup_hooks(ctx);
	return (EXIT_SUCCESS);
}
