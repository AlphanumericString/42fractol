/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_kbs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:51:09 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/01 14:02:11 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	set_english_kb(t_context *ctx)
{
	ctx->kb = KB_QWERTY;
}

void	set_french_kb(t_context *ctx)
{
	ctx->kb = KB_AZERTY;
}
