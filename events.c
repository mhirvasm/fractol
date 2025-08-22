/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirvasm <mhirvasm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:34:15 by mhirvasm          #+#    #+#             */
/*   Updated: 2025/08/22 12:31:14 by mhirvasm         ###   ########.fr       */
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
	if (keysym == KEY_ESC)
		close_handler(fractal);
	if (keysym == KEY_LEFT)
		fractal->shift_x -= (0.3 * fractal->zoom);
	else if (keysym == KEY_RIGHT)
		fractal->shift_x += (0.3 * fractal->zoom);
	else if (keysym == KEY_UP)
		fractal->shift_y += (0.3 * fractal->zoom);
	else if (keysym == KEY_DOWN)
		fractal->shift_y -= (0.3 * fractal->zoom);
	else if (keysym == KEY_PLUS)
		fractal->iterations += 10;
	else if (keysym == KEY_MINUS)
		fractal->iterations -= 10;
	else if (keysym == KEY_C)
	{
		if (fractal->color == COLOR_HOT_PINK)
			fractal->color = COLOR_PSY_RED;
		else
			fractal->color = COLOR_HOT_PINK;
	}
	fractal_render(fractal);
	return (0);
}

int	handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == MOUSE_SCROLL_UP)
		fractal->zoom *= 0.98;
	else if (button == MOUSE_SCROLL_DN)
		fractal->zoom *= 1.02;
	fractal_render(fractal);
	return (0);
}

void	error_and_exit(void)
{
	ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
