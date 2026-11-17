/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:59:03 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/17 11:58:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "fract_ol_types.h"
#include "ft_string.h"
#include "mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>

int	close_hook(t_context *ctx)
{
	mlx_loop_end(ctx->mlx.mlx);
	return (EXIT_SUCCESS);
}

void	zoom_handler(int button, int x, int y, t_context *ctx)
{
	const t_2d_fpoint	rel = {
		.x = (double) x - ctx->mlx.width / 2.0,
		.y = (double) y - ctx->mlx.height / 2.0
	};

	if (button == 4)
	{
		ctx->camera.zoom = ctx->camera.zoom + .01;
		ctx->camera.x = ctx->camera.x + rel.x * .01;
		ctx->camera.y = ctx->camera.y + rel.y * .01;
	}
	else
	{
		ctx->camera.zoom = ctx->camera.zoom - .01;
		ctx->camera.x = ctx->camera.x - rel.x * .01;
		ctx->camera.y = ctx->camera.y - rel.y * .01;
	}
	if (ctx->camera.zoom < 0.01)
		ctx->camera.zoom = 0.01;
	ctx->update_screen = 1;
}

int	mouse_hook_click(int button, int x, int y, t_context *ctx)
{
	if ((button == 4 || button == 5) && ctx->camera.zoom_held != 0)
		return (zoom_handler(button, x, y, ctx), EXIT_SUCCESS);
	if (button == 4)
		ctx->camera.move_speed += 1 % (WIN_WIDTH / 2);
	if (button == 5)
		ctx->camera.move_speed = ft_max(ctx->camera.move_speed, 0);
	if (button == 1)
	{
		ctx->camera.move_held = 1;
		ctx->camera.m_prev.x = x;
		ctx->camera.m_prev.y = y;
		ctx->it_old = ctx->it;
		ctx->it /= 4;
	}
	return (0);
}

int	mouse_hook_act(int x, int y, t_context *ctx)
{
	if (ctx->camera.move_held == 0)
		return (0);
	ctx->camera.x += (ctx->camera.m_prev.x - x) / ctx->camera.zoom;
	ctx->camera.y += (ctx->camera.m_prev.y - y) / ctx->camera.zoom;
	ctx->camera.m_prev.x = x;
	ctx->camera.m_prev.y = y;
	ctx->update_screen = 1;
	return (0);
}

int	mouse_hook_release(int button, int x, int y, t_context *ctx)
{
	if (button == 1)
	{
		ctx->camera.move_held = 0;
		ctx->camera.x += ctx->camera.m_prev.x - x;
		ctx->camera.y += ctx->camera.m_prev.y - y;
		ctx->camera.m_prev.x = 0;
		ctx->camera.m_prev.y = 0;
		ctx->update_screen = 1;
		ctx->it = ctx->it_old;
	}
	return (0);
}
