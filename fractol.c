/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirvasm <mhirvasm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:06:51 by mhirvasm          #+#    #+#             */
/*   Updated: 2025/08/06 15:36:40 by mhirvasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"


int	main(int argc, char *argv[])
{
	t_fractal	fractal;
	
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
		{
			
			fractal.name = argv[1];
			if (!ft_strncmp(fractal.name, "julia", 5))
			{
			fractal.julia_x = ft_atodbl(argv[2]);
			fractal.julia_y = ft_atodbl(argv[3]);
			}
			//TL;DR
			//PROMPT correct, kick off the application
			//1)
			fractal_init(&fractal);
			//2)
			fractal_render(&fractal);
			//3)
			mlx_loop(fractal.mlx_connection);
		}
	else
	{
		//◦ If no parameter is provided, or if the parameter is invalid, the program displays
			//a list of available parameters and exits properly. //TODO
		write(2, "Error", 6);
		exit(EXIT_FAILURE);
	}
}