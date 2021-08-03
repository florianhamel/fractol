/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhamel <fhamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 23:41:30 by fhamel            #+#    #+#             */
/*   Updated: 2021/08/03 15:46:46 by fhamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "fractol.h"

/*
** MY MACROS
*/
# define BURNING_SHIP 3

/*
** EVENTS
*/
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364

/*
** burning_ship_bonus.c
*/
t_comp	z_next_b(t_comp z, t_comp c);
int		get_color_burning_ship(t_comp c, t_data *data);
int		get_pix_burning_ship(int y, int x, t_data *data);
int		**burning_ship(t_data *data);
void	start_burning_ship(int zoom_mode);

/*
** events_bonus.c
*/
void	switch_frame_set(t_mlx_data *mlx_d);
int		key_set(int keypress, t_mlx_data *mlx_d);
int		zoom_set(int button, int x, int y, t_mlx_data *mlx_d);

/*
** movement_bonus.c
*/
void	move_left(t_mlx_data *mlx_d);
void	move_up(t_mlx_data *mlx_d);
void	move_right(t_mlx_data *mlx_d);
void	move_down(t_mlx_data *mlx_d);

/*
** start_bonus.c
*/
void	exit_usage_bonus(int error);
void	start_julia_set(char **av, int zoom_mode);
void	start_mandelbrot_set(int zoom_mode);

#endif
