/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:22:34 by fhamel            #+#    #+#             */
/*   Updated: 2021/08/03 15:47:21 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

/*
** MY_MACROS
*/
# define MANDELBROT 1
# define JULIA 2

# define USAGE 1
# define PARAMS 2

# define ZOOM_MOUSE 1
# define ZOOM_AUTO 2

# define CHILL 1
# define PSYCHO 2

/*
** EVENTS
*/
# define MOUSE_EVENT 4
# define KEY_PRESS 2
# define WIN_QUIT 17

/*
** BUTTONS
*/
# define ZOOM_IN 4
# define ZOOM_OUT 5
# define ESC_KEY 65307
# define COLOR_SWAP 32

/*
** MASKS
*/
# define NO_MASK 0

typedef struct s_comp
{
	double	re;
	double	im;
}		t_comp;

typedef struct s_data
{
	int				win_y;
	int				win_x;
	double			ori_re;
	double			ori_im;
	double			width;
	double			height;
	int				set;
	int				zoom_mode;
	double			zoom_re;
	double			zoom_im;
	int				zoom_pow;
	int				color;
	t_comp			c;
}		t_data;

typedef struct s_mlx_data
{
	t_data	*data;
	int		**arr_pix;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	void	*img_ptr_tmp;
	void	*img_addr_tmp;
	int		bpp;
	int		sl;
	int		endian;
}		t_mlx_data;

/*
** color.c
*/
int			convergence_speed_color(t_comp z);
int			diverge_speed_color(int iter, int max_iter);
int			get_divergence_color(int iter, int max_iter);
int			get_divergence_color_map(int iter);

/*
** events_zoom.c
*/
void		zoom_in(t_data *data);
void		zoom_out(t_data *data);
void		switch_frame(t_mlx_data *mlx_d);

/*
** events.c
*/
int			win_quit(t_mlx_data *mlx_d);
int			win_esc(int keypress, t_mlx_data *mlx_d);
int			zoom(int button, int x, int y, t_mlx_data *mlx_d);

/*
** fractol.c
*/
int			**init_arr_pix(t_data *data);
t_data		*init_data(int set, int zoom_mode);

/*
** image.c
*/
t_mlx_data	*init_mlx_data(t_data *data);
void		free_arr_pix(t_mlx_data *mlx_d);
void		put_pixel(t_mlx_data *mlx_d, int y, int x);
void		fill_img(t_mlx_data *mlx_d);
void		display_fractal(t_mlx_data *mlx_d);

/*
** julia.c
*/
int			get_color_julia(t_comp z0, t_data *data);
int			get_pix_julia(int y, int x, t_data *data);
int			**julia(t_data *data);
void		start_julia(char **av, int zoom_mode);

/*
** mandelbrot.c
*/
int			get_color_mandelbrot(t_comp c, t_data *data);
int			get_pix_mandelbrot(int y, int x, t_data *data);
int			**mandelbrot(t_data *data);
void		start_mandelbrot(int zoom_mode);

/*
** operations.c
*/
t_comp		z_next(t_comp z, t_comp c);
double		modulus(t_comp z);
double		get_re_part(int x, t_data *data);
double		get_im_part(int y, t_data *data);

/*
** parsing.c
*/
int			get_sign(char *p);
double		get_param(char *p);
int			check_param(char *p);

/*
** utils.c
*/
void		*alloc(size_t size, size_t len);
void		ft_exit(void);
void		exit_usage(int error);

#endif