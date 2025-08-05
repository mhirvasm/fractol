/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirvasm <mhirvasm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 09:04:15 by mhirvasm          #+#    #+#             */
/*   Updated: 2025/08/05 13:48:27 by mhirvasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x *(img->bits_per_pixel / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

// z = x^2 +c
// z initially is (0, 0)
// c is the actual point

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	
	// pixel coordinate x && y scaled to fit mandelbrot needs
	c.x =  map(x, -2, +2, 0,  WIDTH) + fractal->shift_x;
	c.y = map(y, +2, -2, 0, HEIGHT) + fractal->shift_y;

	//How many iterations to confirm if its mandelbrot set?
	while(i < fractal->iterations)
	{
		// actual z^2 + c
		// z = z^2 + c 
		
		z = sum_complex(square_complex(z), c); //TODO
		
		//Is the value escaped?
		if ((z.x *z.x) + (z.y *z.y) > fractal->escape_value)
		{
			color = map(i, COLOR_BLACK, COLOR_WHITE, 0, fractal->iterations);
			pixel_put(x, y, &fractal->img, color); //TODO
			return ;
		}
		i++;
	}
	// We are in Mandelbrot set
	pixel_put(x, y, &fractal->img, COLOR_COSMIC_BLUE);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while(++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y ,fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
							fractal->mlx_window,
							fractal->img.img_ptr,
							0, 0);
}