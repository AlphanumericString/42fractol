/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:10:50 by bgoulard          #+#    #+#             */
/*   Updated: 2024/04/25 02:39:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

const char	*ft_shift_args(const char ***args, int *index)
{
	const char	*arg;

	if (*index <= 0 || !*args || !**args)
		return (NULL);
	(*index)--;
	arg = **args;
	(*args)++;
	return (arg);
}
