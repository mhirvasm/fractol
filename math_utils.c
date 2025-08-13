/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirvasm <mhirvasm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 09:17:49 by mhirvasm          #+#    #+#             */
/*   Updated: 2025/08/13 12:56:41 by mhirvasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
[0..799] -> [-2..+2]
*/

double map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return (new_max - new_min) * unscaled_num / old_max + new_min;
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;
	
	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;
	
	result.x = (z.x *z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

