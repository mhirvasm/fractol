/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirvasm <mhirvasm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:06:52 by mhirvasm          #+#    #+#             */
/*   Updated: 2025/08/19 07:51:58 by mhirvasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "libft/printf/ft_printf.h"
# include <stdlib.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

// ERROR MESSAGE
# define ERROR_MESSAGE "Use: ./fractol mandelbrot\n\t./fractol julia <v1> <v2>"

//Use square to keep rendering math simple
# define WIDTH	800
# define HEIGHT 800

// Basic colors
# define COLOR_BLACK        0x000000
# define COLOR_WHITE        0xFFFFFF
# define COLOR_RED          0xFF0000
# define COLOR_GREEN        0x00FF00
# define COLOR_BLUE         0x0000FF

// Vibrant & psychedelic colors
# define COLOR_NEON_GREEN   0x39FF14
# define COLOR_NEON_PINK    0xFF6EC7
# define COLOR_NEON_BLUE    0x1F51FF
# define COLOR_ELECTRIC_LIME 0xCCFF00
# define COLOR_HOT_PINK     0xFF69B4
# define COLOR_ULTRAVIOLET  0x6A0DAD
# define COLOR_BRIGHT_TEAL  0x00FFEF
# define COLOR_TRIPPY_PURPLE 0x9D00FF
# define COLOR_PSY_RED      0xFF003C
# define COLOR_COSMIC_BLUE  0x2E2D88
# define COLOR_FLUO_YELLOW  0xF3FF00

/* ──────────────── EVENTS & KEYCODES (Linux / X11) ──────────────── */

/* Events */
# define EVENT_KEY_PRESS       2
# define EVENT_BUTTON_PRESS    4
# define EVENT_DESTROY_NOTIFY  17

/* Masks */
# define MASK_KEY_PRESS        1L
# define MASK_BUTTON_PRESS     4L
# define MASK_STRUCTURE_NOTIFY 131072L

/* Keyboard keys */
# define KEY_ESC     65307
# define KEY_LEFT    65361
# define KEY_UP      65362
# define KEY_RIGHT   65363
# define KEY_DOWN    65364
# define KEY_PLUS    61     /* '+' */
# define KEY_MINUS   45     /* '-' */

/* Mouse buttons */
# define MOUSE_SCROLL_UP   4
# define MOUSE_SCROLL_DN   5

/* ------------------------------------------------------------------- */
typedef struct s_complex
{
	//		real
	double	x;
	//		i
	double	y;
}				t_complex;

typedef struct s_img
{
	void	*img_ptr; //pointer to image struct
	char	*pixels_ptr; //points to the actual pixels
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_fractal
{
	char	*name;
	//MLX
	void	*mlx_connection; //mlx init()
	void	*mlx_window; //mlx new_window()
	//Image
	t_img	img;

	//Hooks member variables
	double	escape_value; //hypotenusa
	int		iterations; // value tied with the image quality and render time 
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;

}	t_fractal;

/*
*PROTOTYPES
*/

//** init **/
void		fractal_init(t_fractal *fractal);
void		data_init(t_fractal *fractal);

/** render */
void		fractal_render(t_fractal *fractal);

//** math */
double		map(double unscaled_num, double min, double max, double old_max);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);
int			ft_atodbl(char *str, double *output);
//** events */
int			key_handler(int keysym, t_fractal *fractal);
int			handler(int button, int x, int y, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			ft_strcmp(char *s1, char *s2);
void		error_and_exit(void);

#endif