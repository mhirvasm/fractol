/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirvasm <mhirvasm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:06:51 by mhirvasm          #+#    #+#             */
/*   Updated: 2025/08/16 12:41:36 by mhirvasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractal	fractal;
	double		value;

	if ((argc == 2 && !ft_strcmp(argv[1], "mandelbrot"))
		|| (argc == 4 && !ft_strcmp(argv[1], "julia")))
	{
		fractal.name = argv[1];
		if (!ft_strcmp(fractal.name, "julia"))
		{
			if (!ft_atodbl(argv[2], &value) || !ft_atodbl(argv[3], &value))
				error_and_exit();
			ft_atodbl(argv[2], &value);
			fractal.julia_x = value;
			ft_atodbl(argv[3], &value);
			fractal.julia_y = value;
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
		error_and_exit();
}
