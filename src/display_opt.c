/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_opt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:18:51 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/17 13:01:24 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "ft_list_types.h"
#include "ft_string.h"
#include "option.h"

void	print_usage(t_context *ctx)
{
	ft_putstr_fd(ctx->progname, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd("./fract_ol <options> "\
	"[Mandelbrot|Julia|Burningship|Tricorn|Barnfern] "\
	"[fractal arguments (see -h)]\n", 2);
	ft_putstr_fd("\n", 2);
}

void	display_option(t_list *option_list)
{
	t_option	*opt;

	while (option_list)
	{
		opt = (t_option *)option_list->data;
		ft_putstr_fd("\t", 1);
		if (opt->short_name)
		{
			ft_putstr_fd("-", 1);
			ft_putstr_fd(opt->short_name, 1);
			ft_putstr_fd(",\t", 1);
		}
		ft_putstr_fd("--", 1);
		ft_putstr_fd(opt->name, 1);
		ft_putstr_fd(":\t\t", 1);
		ft_putstr_fd(opt->description, 1);
		ft_putstr_fd("\n", 1);
		option_list = option_list->next;
	}
}

void	display_help(t_context *ctx)
{
	ft_putstr_fd("./fract_ol <options> [Mandelbrot|Julia|Tricorn|Burningship"\
	"|Newton] [fractal arguments (see -h)]\n", 1);
	ft_putstr_fd("\n", 1);
	if (ctx->option_list)
	{
		ft_putstr_fd("Options:\n", 1);
		display_option(ctx->option_list);
	}
	ft_putstr_fd("  Mandelbrot:\n"\
	"    <real>: Set the starting number of iterations (MAX : 42)\n"\
	"  Julia:\n"\
	"    <real>: Set the starting value of c (MAX : 10.0)\n"\
	"    <real>: Set the starting value of z (MAX : 10.0)\n"\
	"  Burningship:\n"\
	"    <real>: Set the starting number of iterations (MAX : 42)\n"\
	"  Tricorn:\n"\
	"    <real>: Set the starting value of z (MAX : 10.0)\n"\
	"    <real>: Set the starting value of c (MAX : 10.0)\n"\
	"  Newton:\n"\
	"    <real>: Set the starting number of iterations (MAX : 42)\n", 1);
	ft_putstr_fd("\n", 1);
}

void	display_version(t_context *ctx)
{
	(void)ctx;
	ft_putstr_fd(VERSION, 1);
	ft_putstr_fd("\n", 1);
}

void	set_logmode(t_context *ctx)
{
	ctx->logmode = true;
}
