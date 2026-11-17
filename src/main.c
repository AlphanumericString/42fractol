/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 02:15:13 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/17 13:04:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "fract_ol_types.h"
#include "ft_extended.h"
#include "ft_string.h"
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>

int	fract_ol_argcheck(t_context *ctx, char **av)
{
	if ((ctx->fractal == JULIA) && (!av[1] || !av[2]))
		return (EXIT_FAILURE);
	else if (ctx->fractal != FRACTAL_ERROR && !av[1])
		return (EXIT_FAILURE);
	else if (check_arg_str(ctx, av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ctx->fractal == JULIA)
	{
		ctx->start_c = ft_atof(av[1]);
		ctx->start_z = ft_atof(av[2]);
	}
	else
		ctx->it = ft_atoi(av[1]);
	return (check_arg_range(ctx));
}

//	fractal_str[BARNFERN] = "Barnfern";
int	set_fract(char **av, t_context *ctx)
{
	size_t		i;
	const char	*fractal_str[FRACTAL_ERROR];

	fractal_str[MANDELBROT] = "Mandelbrot";
	fractal_str[JULIA] = "Julia";
	fractal_str[BURNINGSHIP] = "Burningship";
	fractal_str[TRICORN] = "Tricorn";
	fractal_str[NEWTON] = "Newton";
	i = 0;
	ctx->fractal = FRACTAL_ERROR;
	while (i < FRACTAL_ERROR)
	{
		if (!ft_strcmp(av[0], fractal_str[i]))
		{
			ctx->fractal = (t_fractal)i;
			break ;
		}
		i++;
	}
	if (ctx->fractal == FRACTAL_ERROR || fract_ol_argcheck(ctx, av))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_context	prog;
	int			ret;

	ft_memset(&prog, 0, sizeof(t_context));
	if (setup_context(&prog, &ac, &av) == EXIT_FAILURE)
		return (cleanup_context(prog), EXIT_FAILURE);
	exec_options(&prog);
	if (is_progterminfo(prog))
		return (cleanup_context(prog), EXIT_SUCCESS);
	if (ac < 2 || set_fract(av, &prog) == EXIT_FAILURE)
		return (print_usage(&prog), cleanup_context(prog), EXIT_FAILURE);
	ret = fract_ol_main(ac, av, &prog);
	cleanup_context(prog);
	return (ret);
}
