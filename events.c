/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirvasm <mhirvasm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:34:15 by mhirvasm          #+#    #+#             */
/*   Updated: 2025/08/05 14:34:20 by mhirvasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection,
					fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection,
					fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Left)
	fractal->shift_x += 0.1;
	else if (keysym == XK_Right)
	fractal->shift_x -= 0.1;
	else if (keysym == XK_Up)
	fractal->shift_y -= 0.1;
	else if (keysym == XK_Down)
	fractal->shift_y += 0.1;
	else if (keysym == XK_p)//TODO pluus  doesnt work
	fractal->iterations += 10;
	else if (keysym == XK_m)
	fractal->iterations -= 10;
	

	//refresh the image
	fractal_render(fractal);
	
	return (0);
}