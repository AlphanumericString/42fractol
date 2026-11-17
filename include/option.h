/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 08:54:00 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/16 11:30:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTION_H
# define OPTION_H

# include "fract_ol_types.h"
# include <stdint.h>

enum				e_optionflags
{
	STOP_PROG = 0x01,
	CONTINUE_PROG = 0x02,
};

typedef struct s_option
{
	const char		*name;
	const char		*short_name;
	const char		*description;
	void			(*exec)(t_context *ctx);
	uint64_t		flags;
}					t_option;

typedef struct s_option_active
{
	const t_option	*option;
}					t_option_active;

#endif // !OPTION_H
