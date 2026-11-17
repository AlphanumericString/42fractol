/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:34:16 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/17 12:03:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "fract_ol_types.h"
#include "mlx.h"
#include <X11/X.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>

int	key_hook_release(int keycode, t_context *restrict ctx)
{
	if (keycode == XK_Control_L || keycode == XK_Control_R)
	{
		ctx->camera.zoom_held = 0;
	}
	return (0);
}

static inline int	direction_handler(int keycode, int msk, t_context *restrict
									ctx)
{
	const int	kb_keyset[][4] = {
	{XK_Up, XK_Right, XK_Down, XK_Left},
	{XK_z, XK_q, XK_s, XK_d},
	{XK_w, XK_a, XK_s, XK_d},
	};

	(void)msk;
	if (keycode == kb_keyset[KB_UNIVERSAL][0]
		|| keycode == kb_keyset[ctx->kb][0])
		ctx->camera.y += 1 * ctx->camera.move_speed / ctx->camera.zoom;
	if (keycode == kb_keyset[KB_UNIVERSAL][1]
		|| keycode == kb_keyset[ctx->kb][1])
		ctx->camera.x -= 1 * ctx->camera.move_speed / ctx->camera.zoom;
	if (keycode == kb_keyset[KB_UNIVERSAL][2]
		|| keycode == kb_keyset[ctx->kb][2])
		ctx->camera.y -= 1 * ctx->camera.move_speed / ctx->camera.zoom;
	if (keycode == kb_keyset[KB_UNIVERSAL][3]
		|| keycode == kb_keyset[ctx->kb][3])
		ctx->camera.x += 1 * ctx->camera.move_speed / ctx->camera.zoom;
	ctx->update_screen = true;
	return (EXIT_SUCCESS);
}

static inline bool	is_in_set(const int *set, size_t set_size, int check)
{
	size_t		i;
	bool		hit;

	i = 0;
	hit = false;
	while (i < set_size && hit == false)
		if (check == set[i++])
			hit = true;
	return (hit);
}

	// bad move implementation to display mandelbrot when key pressed 
	// as soon as user click swap back to julia with x and y as re and im
static inline int	key_hook_part2(int keycode, t_context *restrict ctx)
{
	if (keycode == XK_Control_L || keycode == XK_Control_R)
	{
		ctx->camera.zoom_held = 1;
		return (EXIT_SUCCESS);
	}
	if (keycode == XK_Page_Up || keycode == XK_Page_Down)
	{
		ctx->it = ctx->it + (keycode == XK_Page_Up) - (keycode == XK_Page_Down);
		ctx->update_screen = 1;
		return (EXIT_SUCCESS);
	}
	if (ctx->fractal == JULIA)
	{
		if (keycode == XK_t)
			ctx->start_z += .1;
		if (keycode == XK_y)
			ctx->start_z -= .1;
		if (keycode == XK_u)
			ctx->start_c += .1;
		if (keycode == XK_i)
			ctx->start_c -= .1;
		ctx->update_screen = true;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	key_hook(int keycode, t_context *restrict ctx)
{
	const int		keyused_spe[] = {XK_Control_R, XK_Control_L, XK_Page_Up,
		XK_Page_Down, XK_Escape, XK_Left, XK_Right, XK_Down, XK_Up
	};
	const int		keyused_al[] = {XK_z, XK_q,	XK_a, XK_s,	XK_d, XK_t, XK_y,
		XK_u, XK_i, XK_w
	};
	const size_t	spe_sz = sizeof(keyused_spe) / sizeof(keyused_spe[0]);
	const size_t	al_sz = sizeof(keyused_al) / sizeof(keyused_al[0]);

	if (!is_in_set(keyused_spe, spe_sz, keycode) && !is_in_set(keyused_al, \
	al_sz, keycode))
		return (0);
	if (keycode == XK_Escape)
		return (mlx_loop_end(ctx->mlx.mlx), EXIT_SUCCESS);
	if (is_in_set((int []){XK_Left, XK_Right, XK_Down, XK_Up, XK_z, XK_q, \
		XK_a, XK_s, XK_d, XK_w}, 10, keycode))
		return (direction_handler(keycode, 0, ctx));
	return (key_hook_part2(keycode, ctx));
}
