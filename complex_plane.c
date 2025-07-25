/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirvasm <mhirvasm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:06:49 by mhirvasm          #+#    #+#             */
/*   Updated: 2025/07/25 18:15:13 by mhirvasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct s_complex
{
	// x
	double	real;
	// y 
	double	i;
}			t_complex;

int	main()
{
		t_complex	z;
		//			point
		t_complex	c;
		double		tmp_real;
		int			i;

		z.real = 0;
		z.i = 0;

		c.real = 5;
		c.i =2;

		i = 0;
		while (i < 42)
		{
			//General formula
			// z = z^2 = c
			tmp_real = (z.real * z.real) - (z.i * z.i);
			z.i = 2 * z.real * z.i;
			z.real = tmp_real;

			//Adding the c value
			z.real += c.real;
			z.i += c.i;

			ft_printf("iteration n -> %d real %d imginary %d\n", i, z.real, z.i); //TODO UPDATE PRINTF
			i++;
			
			
			
		}

		
}
