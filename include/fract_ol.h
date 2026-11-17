/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 02:15:27 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/16 15:05:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "fract_ol_types.h"
# include "ft_list_types.h"
# include "mlx_structs.h"

// src/ft_clamp.c
int			ft_clamp(int value, int min, int max);
float		ft_clamp_f(float value, float min, float max);
double		ft_clamp_d(double value, double min, double max);

// src/checks.c
int			ft_isint(char *str);
int			ft_isfloat(char *str);
int			check_arg_str(t_context *ctx, char **av);
int			check_arg_range(t_context *ctx);

// src/context.c

int			setup_context(t_context *ctx, int *ac, char ***av);
void		cleanup_context(t_context prog);

// src/display_opt.c

void		print_usage(t_context *ctx);
void		display_option(t_list *option_list);
void		display_help(t_context *ctx);
void		display_version(t_context *ctx);
void		set_logmode(t_context *ctx);

// src/draw_fern.c

void		draw_fern(const t_context *ctx);

// src/fract_ol_main.c

void		ft_draw_fractal(t_context *ctx);
void		ft_camera_init(t_camera *cam);
int			fract_ol_main(int ac, char **av, t_context *ctx);

// src/ft_mlx.c

int			ft_mlx_destroy(t_mlx *mlx);
int			ft_mlx_init(t_mlx *mlx, t_context *ctx);

// src/ft_put_pixel.c

void		ft_put_pixel(t_img *data, int x, int y, int color);

// src/hooks_keys.c

int			key_hook_release(int keycode, t_context *ctx);
int			key_hook(int keycode, t_context *ctx);

// src/loop_hooks.c

int			loop_hook(t_context *ctx);

// src/main.c

int			fract_ol_argcheck(t_context *ctx, char **av);
int			set_fract(char **av, t_context *ctx);
int			main(int ac, char **av);

// src/options.c

int			setup_options(t_context *ctx);
int			push_option(t_context *ctx, const char *arg);
bool		is_progterminfo(t_context prog);
void		exec_options(t_context *prog);

// src/other_hooks.c

int			close_hook(t_context *ctx);
void		zoom_handler(int button, int x, int y, t_context *ctx);
int			mouse_hook_click(int button, int x, int y, t_context *ctx);
int			mouse_hook_act(int x, int y, t_context *ctx);
int			mouse_hook_release(int button, int x, int y, t_context *ctx);
int			mouse_hook(int button, int x, int y, t_context *ctx);

// src/pixel_fractals.c

int			pixel_newton(const t_context *ctx, int x, int y);
int			pixel_tricorn(const t_context *ctx, int x, int y);
int			pixel_burningship(const t_context *ctx, int x, int y);
int			pixel_julia(const t_context *ctx, int x, int y);
int			pixel_mandelbrot(const t_context *ctx, int x, int y);

// src/set_kbs.c

void		set_english_kb(t_context *ctx);
void		set_french_kb(t_context *ctx);

#endif /* FRACT_OL_H */
