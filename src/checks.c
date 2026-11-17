/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:18:50 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/17 12:59:34 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "fract_ol_types.h"
#include "ft_string.h"
#include <stddef.h>
#include <stdbool.h>

int	ft_isint(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	if (i > 10 || (i == 10 && ft_strcmp(str, "2147483647") > 0) || \
	(i == 11 && ft_strcmp(str, "-2147483648") > 0))
		return (false);
	return (true);
}

int	ft_isfloat(char *str)
{
	size_t	i;
	size_t	dot;

	i = 0;
	dot = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
			dot++;
		else if (!ft_isdigit(str[i]) && str[i] != '.')
			return (false);
		i++;
	}
	if (i > 10 || i == 0 || dot > 1)
		return (false);
	return (true);
}

int	check_arg_str(t_context *ctx, char **av)
{
	if (ctx->fractal == MANDELBROT || ctx->fractal == BURNINGSHIP || \
	ctx->fractal == TRICORN || ctx->fractal == NEWTON)
	{
		if (ft_isint(av[1]) == false)
			return (ft_putstr_fd("Iterations must be a number. see -h.\n", 2), \
			EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	else if (ft_isfloat(av[2]) == false)
		return (ft_putstr_fd("Z must be a number. See -h\n", 2), EXIT_FAILURE);
	else if (ft_isfloat(av[1]) == false)
		return (ft_putstr_fd("C must be a number. See -h\n", 2), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_arg_range(t_context *ctx)
{
	if ((ctx->fractal == MANDELBROT || ctx->fractal == BURNINGSHIP || \
	ctx->fractal == TRICORN || ctx->fractal == NEWTON) && \
	(ctx->it > MAX_ITERATIONS || ctx->it < 1))
	{
		ft_putstr_fd("Warning: Iterations are clamped between 1 and 42\n", 2);
		return (ctx->it = ft_clamp(ctx->it, 1, MAX_ITERATIONS), EXIT_SUCCESS);
	}
	else if (ctx->start_c > 10.0 || ctx->start_c < -10.0)
	{
		ft_putstr_fd("Warning: c must be between -10.0 and 10.0\n", 2);
		ctx->start_c = ft_clamp_f(ctx->start_c, -10.0, 10.0);
	}
	else if (ctx->start_z > 10.0 || ctx->start_z < -10.0)
	{
		ft_putstr_fd("Warning: z must be between -10.0 and 10.0\n", 2);
		ctx->start_z = ft_clamp_f(ctx->start_z, -10.0, 10.0);
	}
	return (EXIT_SUCCESS);
}
