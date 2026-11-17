/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intrange.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:22:01 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/01 14:01:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_irange(int x, int min, int max, int new_max)
{
	int	res;

	res = x + min;
	max += min;
	return ((int)(((double)res / max) * new_max));
}

float	ft_frange(float x, float min, float max, float new_max)
{
	float	res;

	res = x + min;
	max += min;
	return ((res / max) * new_max);
}

double	ft_dbrange(double x, double min, double max, double new_max)
{
	double	res;

	res = x + min;
	max += min;
	return ((res / max) * new_max);
}
