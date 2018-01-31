/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

static void	display_color(t_env *e)
{
	mlx_string_put(e->mlx, e->win, WIN_L - 220, 35, WHITE,
	"COLOR:");
	if (e->palette == UNICOLOR)
		mlx_string_put(e->mlx, e->win, WIN_L - 160, 35, PYELLOW, "UNICOLOR");
	if (e->palette == MOEBIUS)
		mlx_string_put(e->mlx, e->win, WIN_L - 160, 35, WBLUE2, "MOEBIUS");
	if (e->palette == FLASH)
		mlx_string_put(e->mlx, e->win, WIN_L - 160, 35, PPINK, "FLASH");
}

static void	display_name(t_env *e)
{
	mlx_string_put(e->mlx, e->win, WIN_L - 220, 20, WHITE,
	"SET:");
	if (e->type == MANDELBROT)
		mlx_string_put(e->mlx, e->win, WIN_L - 180, 20, WHITE, "MANDELBROT");
	if (e->type == MANDELBRAT)
		mlx_string_put(e->mlx, e->win, WIN_L - 180, 20, WHITE, "MANDELBRAT");
	if (e->type == JULIA)
		mlx_string_put(e->mlx, e->win, WIN_L - 180, 20, WHITE, "JULIA");
	if (e->type == JULIABRAT)
		mlx_string_put(e->mlx, e->win, WIN_L - 180, 20, WHITE, "JULIABRAT");
	if (e->type == BURNINGSHIP)
		mlx_string_put(e->mlx, e->win, WIN_L - 180, 20, WHITE, "BURNINGSHIP");
	if (e->type == BURNINGJULIA)
		mlx_string_put(e->mlx, e->win, WIN_L - 180, 20, WHITE, "BURNINGJULIA");
}

void		display_data(t_env *e)
{
	display_name(e);
	display_color(e);
	mlx_string_put(e->mlx, e->win, WIN_L - 220, 50, WHITE,
	"ITERATIONS:");
	mlx_string_put(e->mlx, e->win, WIN_L - 110, 50, WHITE, ft_itoa(e->maxiter));
}

void		display_menu(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 20, 20, WHITE,
	"Scroll to zoom in or out");
	mlx_string_put(e->mlx, e->win, 20, 35, WHITE,
	"Use WASD to move around");
	mlx_string_put(e->mlx, e->win, 20, 65, WHITE,
	"Use 'I' and 'U' to increase/decrease the iterations");
	mlx_string_put(e->mlx, e->win, 20, 80, WHITE,
	"Use 'P' to switch palette");
	mlx_string_put(e->mlx, e->win, 20, 95, WHITE,
	"To reset everything use the DELETE Key");
	mlx_string_put(e->mlx, e->win, 20, 50, WHITE,
	"Use the direction pad to stretch the figure");
	mlx_string_put(e->mlx, e->win, 20, 125, WHITE,
	"(Use 'H' to hide menu and data)");
	if (e->type == JULIA || e->type == JULIABRAT || e->type == BURNINGJULIA)
		mlx_string_put(e->mlx, e->win, 20, 110, WHITE,
	"Use 'M' to toggle movement");
}
