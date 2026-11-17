/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:24:27 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/17 12:56:35 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "fract_ol_types.h"
#include "ft_list.h"
#include "ft_string.h"

int	setup_context(t_context *ctx, int *ac, char ***av)
{
	int	i;

	i = 0;
	ctx->progname = ft_shift_args((const char ***)av, ac);
	if (setup_options(ctx) == -1)
		return (ft_putstr_fd("Error: setup_options failed\n", 2), EXIT_FAILURE);
	while (i < *ac && (*av)[i][0] == '-')
		if (push_option(ctx, (*av)[i++]))
			return (EXIT_FAILURE);
	*av += i;
	*ac -= i;
	set_english_kb(ctx);
	ctx->it = DEFAULT_ITERATIONS;
	ctx->fractal = FRACTAL_ERROR;
	return (EXIT_SUCCESS);
}

void	cleanup_context(t_context prog)
{
	ft_listclear(&prog.option_list, NULL);
	ft_listclear(&prog.option_active_list, NULL);
}
