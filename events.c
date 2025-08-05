/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirvasm <mhirvasm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:34:15 by mhirvasm          #+#    #+#             */
/*   Updated: 2025/08/05 13:59:05 by mhirvasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int keysym, t_fractal *fractal)
{
	//if (keysym == XK_Escape)
		//close_handler(fractal);
	if (keysym == XK_Left)
	fractal->shift_x += 0.1;
	else if (keysym == XK_Right)
	fractal->shift_x -= 0.1;
	else if (keysym == XK_Up)
	fractal->shift_y -= 0.1;
	else if (keysym == XK_Down)
	fractal->shift_y += 0.1;
	//else if (keysym == XK_plus)
	//fractal->iterations += 10;
	//else if (keysym == XK_minus)
	//fractal->iterations -+ 10;
	

	//refresh the image
	fractal_render(fractal);
	
	return (0);
}