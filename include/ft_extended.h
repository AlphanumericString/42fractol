/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extended.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:00:26 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/06 13:05:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXTENDED_H
# define FT_EXTENDED_H

# include "ft_complex_type.h"

// src/ft_strisnum.c

int			ft_strisnum(const char *str);

// src/ft_intrange.c

int			ft_irange(int x, int min, int max, int new_max);
float		ft_frange(float x, float min, float max, float new_max);
double		ft_dbrange(double x, double min, double max, double new_max);

// src/ft_atof.c

double		ft_atof(const char *str);

// src/ft_complex.c

double		ft_complex_abs(t_complex nb);
t_complex	ft_complex_addl(t_complex nb, long factor);
t_complex	ft_complex_mull(t_complex nb, long factor);
t_complex	ft_complex_muld(t_complex nb, double factor);

#endif  /* FT_EXTENDED_H */
