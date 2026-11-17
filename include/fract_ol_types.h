/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_types.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:11:21 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/17 11:11:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_TYPES_H
# define FRACT_OL_TYPES_H

# include "ft_complex_type.h"
# include "ft_list_types.h"
# include "mlx_structs.h"
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

# define XK_LATIN_1
# include <X11/keysym.h>

# define WIN_HEIGHT 600
# define WIN_WIDTH 800
# define MAX_ZOOM 2
# define MAX_ITERATIONS 42
# define MIN_ITERATIONS 1
# define DEFAULT_ITERATIONS 20
# define VERSION "fract_ol 1.0.0"
# define EBAD_FRACT -2

typedef enum e_fractal
{
	MANDELBROT,
	JULIA,
	BURNINGSHIP,
	TRICORN,
	BARNFERN,
	NEWTON,
	FRACTAL_ERROR
}				t_fractal;

typedef enum e_kb_type
{
	KB_UNIVERSAL = 0,
	KB_AZERTY = 1,
	KB_QWERTY = 2,
}				t_kb_type;

typedef struct s_2dlfpoint
{
	double		x;
	double		y;
}				t_2d_fpoint;

typedef struct s_2d_point
{
	long		x;
	long		y;
}				t_2dpoint;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	size_t		height;
	size_t		width;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx;

typedef struct s_camera
{
	double		x;
	double		y;
	bool		move_held;
	t_2d_fpoint	m_prev;
	double		move_speed;
	bool		zoom_held;
	double		zoom;
	double		zoom_speed;
}				t_camera;

//t_complex julia move start_c and start_z to here
typedef struct s_context
{
	const char	*progname;
	bool		logmode;
	bool		update_screen;
	t_list		*option_list;
	t_list		*option_active_list;
	t_kb_type	kb;
	t_fractal	fractal;
	t_mlx		mlx;
	t_camera	camera;
	t_complex	julia;
	double		start_z;
	double		start_c;
	size_t		it;
	size_t		it_old;
}				t_context;

#endif /* FRACT_OL_TYPES_H */
