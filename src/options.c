/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:23:21 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/16 12:15:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "ft_list.h"
#include "ft_list_types.h"
#include "ft_string.h"
#include "option.h"

int	setup_options(t_context *ctx)
{
	static const t_option	options[] = {
	{"help", "h", "Display this help message", display_help, STOP_PROG},
	{"version", "v", "Display the version of the program", display_version,
		CONTINUE_PROG},
	{"log", "l", "Set the program to log output (debug info in term)",
		set_logmode, CONTINUE_PROG},
	{"english", "e", "Set the program to use an english keyboard",
		set_english_kb, CONTINUE_PROG},
	{"french", "f", "Set the program to use a french keyboard (default: " \
		"english keyboard)", set_french_kb, CONTINUE_PROG},
	{NULL, NULL, NULL, NULL, STOP_PROG}
	};
	int						i;

	i = 0;
	while (options[i].exec)
	{
		if (ft_listpush(&ctx->option_list, &options[i]) == NULL)
			return (-1);
		i++;
	}
	return (0);
}

int	push_option(t_context *ctx, const char *arg)
{
	const char	*tmp = ft_strrchr(arg, '-');
	t_list		*option_runner;

	if (!tmp)
		return (EXIT_FAILURE);
	tmp++;
	option_runner = ctx->option_list;
	while (option_runner)
	{
		if (!ft_strcmp(((t_option *)option_runner->data)->name, tmp) || \
		!ft_strcmp(((t_option *)option_runner->data)->short_name, tmp))
		{
			if (!ft_listpush(&ctx->option_active_list, option_runner->data))
				return (EXIT_FAILURE);
		}
		option_runner = option_runner->next;
	}
	return (EXIT_SUCCESS);
}

bool	is_progterminfo(t_context prog)
{
	t_list	*runner;

	runner = prog.option_active_list;
	while (runner)
	{
		if (((t_option *)runner->data)->flags & STOP_PROG)
			return (true);
		runner = runner->next;
	}
	return (false);
}

void	exec_options(t_context *prog)
{
	t_list	*runner;

	runner = prog->option_active_list;
	while (runner)
	{
		((t_option *)runner->data)->exec(prog);
		runner = runner->next;
	}
}
